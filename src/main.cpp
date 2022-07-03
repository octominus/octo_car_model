//
// Created by octominus on 20.06.2022.
//

#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <nav_msgs/Path.h>
#include <visualization_msgs/Marker.h>

#include "RobotModel.h"
#include "CubicSpliner.h"

nav_msgs::Path exact_path;
bool newPath = 0;

void PathCallback(const nav_msgs::Path path) {
    newPath = 1;
    exact_path = path;
}

std::vector<std::vector<float>> CalculateSpline(std::vector<float> x, std::vector<float> y, float dt) {
    std::vector<std::vector<float>> result;
    std::vector<float> rx, ry, ryaw, rk, rs;
    std::vector<float> ixy;
    uint32_t index;
    CubicSpline2D sp(x, y);
    auto s = xt::arange<float>(0.0, sp._s.back(), dt);
    for (index = 0; index < s.size(); index++) {
        ixy = sp.CalculatePosition(s(index));
        rx.push_back(ixy[0]);
        ry.push_back(ixy[1]);
        ryaw.push_back(sp.CalculateYaw(s(index)));
        rk.push_back(sp.CalculateCurvature(s(index)));
        rs.push_back(s(index));
    }
    result = {rx, ry, ryaw, rk, rs};
    return result;
}

std::vector<float> getPathPoints(nav_msgs::Path path, char dim) {
    uint8_t loop_index;
    std::vector<float> points;
    if (dim == 'x') {
        for (loop_index = 0; loop_index < path.poses.size(); loop_index++) {
            points.push_back(path.poses[loop_index].pose.position.x);
        }
    }
    if (dim == 'y') {
        for (loop_index = 0; loop_index < path.poses.size(); loop_index++) {
            points.push_back(path.poses[loop_index].pose.position.y);
        }
    }
    return points;
}

visualization_msgs::Marker markerDefine(float x, float y, float yaw) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time();
    marker.ns = "my_namespace";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0.2;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = yaw;
    marker.scale.x = 3;
    marker.scale.y = 3;
    marker.scale.z = 3;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    //only if using a MESH_RESOURCE marker type:
    //marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";
    return marker;
}

int main(int argc, char **argv) {
    bool isNotReach = 0, isInit = 0;
    float index_l;
    float index_t;
    std::vector<std::vector<float>> result;
    visualization_msgs::Marker robot_marker;
    nav_msgs::Path car_path;
    geometry_msgs::PoseStamped car_pose;
    car_path.header.frame_id = "map";
    float cal_vel = 0.0;
    float des_vel = 10.0; // m/s
    DynamicModel robot_dynamic;
    KinematicModel robot_kinematic;

    ros::init(argc, argv, "octo_car_model");
    std::cout << "Robot drive node status: OK!" << std::endl;

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/rrt_star_server/exact_path", 1000, PathCallback);
    ros::Publisher vis_pub = n.advertise<visualization_msgs::Marker>( "visualization_marker", 0);
    ros::Publisher car_path_pub = n.advertise<nav_msgs::Path>( "car_path", 0);
    ros::Publisher ct_err_pub = n.advertise<std_msgs::Float32>( "cross_track_error", 0);
    ros::Publisher h_err_pub = n.advertise<std_msgs::Float32>( "heading_error", 0);
    ros::Rate loop_rate(10); // 10 Hz -> 0.1 sn

    while (ros::ok()) {
        if (newPath == 1 && !isInit) {
            std::vector<float> x_points = getPathPoints(exact_path, 'x');
            std::vector<float> y_points = getPathPoints(exact_path, 'y');
            result = CalculateSpline(x_points, y_points, 0.1);
            robot_kinematic.robot_state.x = 90;
            robot_kinematic.robot_state.y = 90;
            robot_kinematic.robot_state.yaw = 0;
            robot_kinematic.robot_state.v = 0.0;
            robot_marker = markerDefine(robot_kinematic.robot_state.x, robot_kinematic.robot_state.y, robot_kinematic.robot_state.yaw);
            index_l = result[0].size() - 1;
            std::vector<float> _indx_err = robot_kinematic.CalculateTargetIndex(robot_kinematic.robot_state, result[0], result[1]);
            index_t = _indx_err[0];
            isNotReach = index_l > index_t;
            isInit = 1;
        }
        
        if (isNotReach) {
            // drive functions
            cal_vel = robot_dynamic.StateMachine(des_vel);
            std::vector<float> _del_t_indx = robot_kinematic.KinematicController(robot_kinematic.robot_state, result[0], result[1], result[2], index_t);
            float delta = _del_t_indx[0];
            index_t = _del_t_indx[1];
            robot_kinematic.UpdateStates(&robot_kinematic.robot_state, cal_vel, delta);
            isNotReach = index_l > index_t;
            std_msgs::Float32 ct_err;
            std_msgs::Float32 h_err;
            ct_err.data = _del_t_indx[3];
            h_err.data = _del_t_indx[2];
            std::cout << "Cross Track Error: " << ct_err.data << std::endl;
            std::cout << "Heading Error: " << h_err.data << std::endl;
            std::cout << "Path Yaw: " << result[2][index_t] << std::endl;
            std::cout << "------------------" << std::endl;
            robot_marker = markerDefine(robot_kinematic.robot_state.x, robot_kinematic.robot_state.y, robot_kinematic.robot_state.yaw);
            car_pose.header.frame_id = "map";
            car_pose.pose.position.x = robot_kinematic.robot_state.x;
            car_pose.pose.position.y = robot_kinematic.robot_state.y;
            car_pose.pose.position.z = 0.1;
            car_pose.pose.orientation.w = robot_kinematic.robot_state.yaw;
            car_path.poses.push_back(car_pose);
            ct_err_pub.publish(ct_err);
            h_err_pub.publish(h_err);
            vis_pub.publish(robot_marker);
            car_path_pub.publish(car_path);
        } else {
            //newPath = 0;
            //isInit = 0;
        }
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}

