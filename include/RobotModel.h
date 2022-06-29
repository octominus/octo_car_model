//
// Created by octominus on 20.06.2022.
//

#ifndef WS_DRIVE_ROBOT_ROBOTMODEL_H
#define WS_DRIVE_ROBOT_ROBOTMODEL_H
// ROS Files
#include <ros/ros.h>
#include <nav_msgs/Path.h>

// C++ Files
#include <iostream>
#include <cmath>
#include <vector>

// need to install xtensor
// sudo apt-get install xtensor-dev
// https://xtensor.readthedocs.io/en/latest/numpy.html

#include <xtensor/xarray.hpp>
#include <xtensor/xadapt.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xsort.hpp>
#include <xtensor-blas/xlinalg.hpp>

#define PI 3.14159265359

typedef xt::xarray<float> f_array;

class DynamicModel {
public:
    explicit DynamicModel();
    float StateMachine(float d_spd);
    float BrakeController(float err);
    float InjectionController(float err);
    float DrivingController(float spd_d);
    float MotorForceGenerator(float e_spd);
    float BrakeForceGenerator(float b_frc);
    float ForcetVelocityConverter(float f);
private:
    // Some constants
    std::vector<float> _gear_ratio = {15.0, 13.83, 12.66, 11.49, 10.32, 9.15, 8.0, 7, 6, 5, 4, 3, 2};
    uint _gear = 0;
    float _velocity_c = 0.0; // m/s
    float _T_max = 2100.0; // Nm
    float _w_max = 136.1356815; // rad/s
    float _Beta = 0.4;
    float _velocity_max = 16; // 57.6 km/h = 16 m/s
    float _mass = 8000.0; // kg
    float _T_s = 0.1; // sampling time
    struct {
        float kp    = 4.8;
        float ki    = 0.08;
        float err_l = 0.0;
        float i_l   = 0.0;
        float i     = 0.0;
    } _inj;
    struct {
        float kp = 4.8;
    } _brk;
    struct {
        float x_d_d     = 0.0; // acceleration
        float x_d       = 0.0; // velocity
        float x_d_last  = 0.0; // last velocity
    } _fav;
};

class KinematicModel {
public:
    struct state{
        float x;
        float y;
        float v;
        float yaw;
    } robot_state;
    void UpdateStates(struct state *st, float speed, float delta);
    float NormalizeAngle(float angle);
    float SpeedController(float vel_d, float vel_c);
    std::vector<float> KinematicController(struct state st, std::vector<float> cx, std::vector<float> cy, std::vector<float> cyaw, uint idx_last);
    std::vector<float> CalculateTargetIndex(struct state st, std::vector<float> cx, std::vector<float> cy);
private:
    // Some constants
    struct state _state;
    float _T_s = 0.1; // seconds
    float _car_wb = 3.6; // meters
    float _cntrl_gain = 0.5;
    float _speed_kp = 1.0;
    struct {
        float max_d = 480.0; // angle degree
        float max_r = max_d / (PI / 180);
        float ratio = 20.0;
    } _steer;
};

#endif //WS_DRIVE_ROBOT_ROBOTMODEL_H