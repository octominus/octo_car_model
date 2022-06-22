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
    float velocity = 0.0;
    while (ros::ok())
    {
        /* code */
        Robot.StateMachine(10.0);
        std_msgs::Float32 float_msg;
        float_msg.data = velocity;
        ROS_INFO("Velocity: %f", float_msg.data);
        chatter_pub.publish(float_msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++velocity;
    }
    return 0;
}

