//
// Created by octominus on 20.06.2022.
//

#include "RobotModel.h"

DynamicModel::DynamicModel() {
    // default code
}

float DynamicModel::StateMachine(float d_spd) {
    float force = 0.0;
    force = DrivingController(d_spd);
    _velocity_c = ForcetVelocityConverter(force);
    return _velocity_c;
}

float DynamicModel::DrivingController(float spd_d) {
    float error = spd_d - _velocity_c;
    float f_engine = 0.0, f_brake = 0.0, force = 0.0;
    float injection = 0.0, brake = 0.0;
    // Şimdilik sadece ileri vites durumu için
    bool isReverse = (spd_d < 0);
    if (!isReverse && error < 0.0) {
        brake = BrakeController(error);
        f_brake = BrakeForceGenerator(brake);
        //std::cout << "(Brake) Force: " << f_brake << std::endl;
        force = f_brake;
    } else if (!isReverse && error > 0.0) {
        injection = InjectionController(error);
        f_engine = MotorForceGenerator(injection);
        //std::cout << "(Engine) Force: " << f_engine << std::endl;
        force = f_engine;
    }
    return force;
}

float DynamicModel::InjectionController(float err) {
    float output = 0.0;
    // error -> 1/s
    _inj.i = _inj.i_l + (_T_s * (err + _inj.err_l) / 2);
    output = (_inj.kp * err) + (_inj.ki * _inj.i);
    if (output > _velocity_max) {
        output = _velocity_max;
    }
    output = output / _velocity_max;
    _inj.err_l = err;
    _inj.i_l = _inj.i;
    //std::cout << "(Injection) Error: " << output << std::endl;
    return output;
}

float DynamicModel::BrakeController(float err) {
    float output = 0.0;
    output = _brk.kp * err;
    if (output < 0.0) {
        output = 0.0;
    }
    output = output / _velocity_max;
    //std::cout << "(Brake) Error: " << output << std::endl;
    return output;
}

float DynamicModel::MotorForceGenerator(float e_spd) {
    float torque = 0.0, engine_force = 0.0;
    if ((_gear < _gear_ratio.size()) && ((_velocity_c * _gear_ratio[_gear]) > (0.7 * _w_max))) {
        std::cout << "Gear Up!\nGear: " << _gear << std::endl;
        std::cout << "Gear Ratio: " << _gear_ratio[_gear] << std::endl;
        std::cout << "Velocity: " << _velocity_c << std::endl;
        _gear++;
    }
    auto T_cn = [this](float vel_c, float g_ratio) {
        float omega = g_ratio * vel_c;
        float T_cn = _T_max * ( 1 - ( _Beta * pow(( ( omega / _w_max ) - 1 ), 2) ) );
        return T_cn;
    };
    torque = T_cn(_velocity_c, _gear_ratio[_gear]) * e_spd;
    engine_force = torque * _gear_ratio[_gear];
    return engine_force;
}

float DynamicModel::BrakeForceGenerator(float b_frc) {
    if ((_gear > 0) && ((_velocity_c * _gear_ratio[_gear]) < (0.6 * _w_max))) {
        std::cout << "Gear Down!\nGear: " << _gear << std::endl;
        std::cout << "Gear Ratio: " << _gear_ratio[_gear] << std::endl;
        std::cout << "Velocity: " << _velocity_c << std::endl;
        _gear--;
    }
    return b_frc * _mass * 5;
}

float DynamicModel::ForcetVelocityConverter(float f) {
    // a = x_d_d
    // x_d_d = (x_d - x_d_last) / T_s
    // x_d = (x_d_d * T_s) + x_d_last
    _fav.x_d_d = f / _mass;
    _fav.x_d = (_fav.x_d_d * _T_s) + _fav.x_d_last;
    _fav.x_d_last = _fav.x_d;
    return _fav.x_d;
}