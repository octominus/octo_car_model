//
// Created by octominus on 24.06.2022.
//

#include "RobotModel.h"

KinematicModel::KinematicModel(float x, float y, float v, float yaw) {
    _state.x = x;
    _state.y = y;
    _state.v = v;
    _state.yaw = yaw;
}

void KinematicModel::UpdateStates(float accel, float delta) {
    if (delta > _steer.max_r) {
        delta = _steer.max_r;
    } else if (delta < -_steer.max_r) {
        delta = -_steer.max_r;
    }

    _state.x += _state.v * std::cos(_state.yaw) * _T_s;
    _state.y += _state.v * std::sin(_state.yaw) * _T_s;
    _state.yaw += (_state.v / _car_wb) * std::tan(delta) * _T_s;
    _state.yaw = NormalizeAngle(_state.yaw);
    _state.v += accel * _T_s;
}

float KinematicModel::NormalizeAngle(float angle) {
    // angle type is need to be radian
    while(angle > PI)
        angle -= 2.0 * PI;

    while(angle < -PI)
        angle += 2.0 * PI;

    return angle;
}

float KinematicModel::SpeedController(float vel_d, float vel_c) {
    return _speed_kp * (vel_d - vel_c);
}

std::vector<float> KinematicModel::KinematicController(std::vector<float> curr_x, std::vector<float> curr_y, std::vector<float> curr_yaw, uint idx_last) {
    
}