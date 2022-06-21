//
// Created by octominus on 20.06.2022.
//

#include "RobotModel.h"

DynamicModel::DynamicModel(float vel_d) : _velocity_d(vel_d) {
    float output = 0.0;
    output = DrivingController();
    std::cout << "Force: " << output << std::endl;
}

float DynamicModel::DrivingController() {
    float error = _velocity_d - _velocity_c;
    float f_engine = 0.0, f_brake = 0.0;
    float injection = 0.0, brake = 0.0;
    // Şimdilik sadece ileri vites durumu için
    bool isReverse = (_velocity_d < 0);
    if (!isReverse && error < 0.0) {
        brake = BrakeController(error);
        f_brake = BrakeForceGenerator(brake);
        return f_brake;
    } else if (!isReverse && error > 0.0) {
        injection = InjectionController(error);
        f_engine = MotorForceGenerator(injection);
        return f_engine;
    }
}

float DynamicModel::InjectionController(float err) {
    float output = 0.0;
    if (err > _velocity_max) {
        err = _velocity_max;
    }
    output = err / _velocity_max;
    return output;
}

float DynamicModel::BrakeController(float err) {
    float output = 0.0;
    if (err > _velocity_max) {
        err = _velocity_max;
    }
    output = output / _velocity_max;
    return output;
}

float DynamicModel::MotorForceGenerator(float e_spd) {
    float torque = 0.0, engine_force = 0.0;
    auto T_cn = [this](float vel_c, float g_ratio) {
        float omega = g_ratio * vel_c;
        float T_cn = _T_max * ( 1 - ( _Beta * pow(( ( omega / _w_max ) - 1 ), 2) ) );
        return T_cn;
    };
    torque = T_cn(_velocity_c, _gear_ratio) * e_spd;
    engine_force = torque * _gear_ratio;
    return engine_force;
}

float DynamicModel::BrakeForceGenerator(float b_frc) {
    return -100.0;
}

float DynamicModel::ForcetVelocityConverter() {
    // a = x_d_d
    // x_d_d = (x_d - x_d_last) / T_s
    // x_d = (x_d_d * T_s) + x_d_last
    return 0.0;
}