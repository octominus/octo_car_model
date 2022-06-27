//
// Created by octominus on 20.06.2022.
//

#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <std_msgs/String.h>

#include "RobotModel.h"
#include "robot_planner/path_result.h"
#include "robot_planner/data_result.h"

void chatterCallback(const robot_planner::path_result::ConstPtr& results) {
    robot_planner::data_result result = results->result[0];
    float cx = result.cx;
    ROS_INFO("I heard: [%f]", cx);
}

int main(int argc, char **argv) {
    DynamicModel Robot_Dynamic;
    KinematicModel Robot_Kinematic(0, 0, 0, 0);

    float des_vel = 10.0; // m/s

    ros::Rate loop_rate(10); // 10 Hz -> 0.1 sn

    ros::init(argc, argv, "robot_drive");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/drive_data", 1000, chatterCallback);

    ros::spinOnce();
    loop_rate.sleep();
    return 0;
}

