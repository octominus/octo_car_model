//
// Created by octominus on 24.06.2022.
//

#include "RobotModel.h"

void KinematicModel::UpdateStates(struct state *st, float speed, float delta) {
    if (delta > _steer.max_r) {
        delta = _steer.max_r;
    } else if (delta < -_steer.max_r) {
        delta = -_steer.max_r;
    }

    st->x += st->v * std::cos(st->yaw) * _T_s;
    st->y += st->v * std::sin(st->yaw) * _T_s;
    st->yaw += (st->v / _car_wb) * std::tan(delta) * _T_s;
    st->yaw = NormalizeAngle(st->yaw);
    st->v = speed;
    std::cout << "Speed: " << st->v << std::endl;
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

std::vector<float> KinematicModel::KinematicController(struct state st ,std::vector<float> cx, std::vector<float> cy, std::vector<float> cyaw, uint idx_last) {
    std::vector<float> curr_tar_indx_error = CalculateTargetIndex(st, cx, cy);
    uint curr_target_index = static_cast<uint>(curr_tar_indx_error[0]);
    float error_front_axle = curr_tar_indx_error[1];

    if (idx_last >= curr_target_index) {
        curr_target_index = idx_last;
    }

    float theta_e = NormalizeAngle(cyaw[curr_target_index] - st.yaw);
    float theta_d = atan2(_cntrl_gain * error_front_axle, st.v);
    float delta = theta_e + theta_d;
    return {delta, curr_tar_indx_error[0]};
}

std::vector<float> KinematicModel::CalculateTargetIndex(struct state st, std::vector<float> cx, std::vector<float> cy) {
    // Calc front axle position
    float fx = st.x + _car_wb * cos(st.yaw);
    float fy = st.y + _car_wb * sin(st.yaw);
    // Search nearest point index
    std::vector<float> dx_, dy_;
    uint index;
    for (index = 0; index < cx.size(); index++) {
        dx_.push_back(fx - cx[index]);
        dy_.push_back(fy - cy[index]);
    }
    f_array dx = xt::adapt(dx_);
    f_array dy = xt::adapt(dy_);
    f_array d = xt::hypot(dx, dy);
    f_array target_idx = xt::argmin(d);
    float target_index = target_idx(0);
    float front_axle_vec_x = -cos(st.yaw + (PI / 2));
    float front_axle_vec_y = -sin(st.yaw + (PI / 2));
    float error_front_axle = (dx(target_index) * front_axle_vec_x) + (dy(target_index) * front_axle_vec_y);
    return {target_index, error_front_axle};
}