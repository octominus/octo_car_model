//
// Created by octominus on 20.06.2022.
//

#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <std_msgs/Float32.h>

#include "RobotModel.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("chatter", 1000);
    ros::Rate loop_rate(10); // 10 Hz -> 0.1 sn
    DynamicModel Robot;
    uint vel_change = 0;
    float des_vel = 16.0;
    while (ros::ok())
    {
        /* code */
        std_msgs::Float32 float_msg;
        float_msg.data = Robot.StateMachine(des_vel);
        // ROS_INFO("Velocity: %f", float_msg.data * 3.6);
        if(vel_change > 150) {
            std::cout << "Velocity Changed!" << std::endl;
            if (des_vel > 15.0) {
                des_vel = 5.0;
            } else {
                des_vel = 16.0;
            }
            vel_change = 0;
        }
        vel_change++;
        chatter_pub.publish(float_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}

