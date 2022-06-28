//
// Created by octominus on 20.06.2022.
//

#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <nav_msgs/Path.h>

#include "RobotModel.h"

void PathCallback(const nav_msgs::Path results) {
    //ROS_INFO("First Element: [%f]", results.poses[0].pose.position.x);
    std::cout << results.poses[0].pose.position.x << std::endl;
}

int main(int argc, char **argv) {
    DynamicModel Robot_Dynamic;
    KinematicModel Robot_Kinematic(0, 0, 0, 0);

    float des_vel = 10.0; // m/s
    bool isReach = 0, newPath = 0;

    std::cout << "Desired speed: " << des_vel << std::endl;
    ros::init(argc, argv, "octo_car_model");
    std::cout << "Robot drive node status: OK!" << std::endl;
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/rrt_star_server/exact_path", 1000, PathCallback);
    ros::Rate loop_rate(10); // 10 Hz -> 0.1 sn
    while (newPath) {
        if (!isReach) {
            // drive functions
        } else {
            newPath = 0;
        }
        loop_rate.sleep();
    }
    ros::spin();
    return 0;
}

