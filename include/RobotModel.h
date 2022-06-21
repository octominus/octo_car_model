//
// Created by octominus on 20.06.2022.
//

#ifndef WS_DRIVE_ROBOT_ROBOTMODEL_H
#define WS_DRIVE_ROBOT_ROBOTMODEL_H

// ROS Files
#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>

// C++ Files
#include <iostream>
#include <cmath>

class DynamicModel {
public:
    explicit DynamicModel(float vel_d);
    float BrakeController(float err);
    float InjectionController(float err);
    float DrivingController();
    float MotorForceGenerator(float e_spd);
    float BrakeForceGenerator(float b_frc);
    float ForcetVelocityConverter();
private:
    // Some constants
    float _gear_ratio = 5.0;
    float _velocity_c = 12.8;
    float _velocity_d = 0.0;
    float _T_max = 2100.0; // Nm
    float _w_max = 136.1356815; // rad/s
    float _Beta = 0.4;
    float _velocity_max = 16.8; // 60 km/h = 16.8 m/s
};

class KinematicModel {
public:
    explicit KinematicModel();
private:
    // Some constants
};

class CarModel {
public:
    explicit CarModel();

};


#endif //WS_DRIVE_ROBOT_ROBOTMODEL_H