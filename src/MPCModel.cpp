#include <math.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/QR>

int main() {
//
//  // MPC is initialized here!
//    MPC mpc;
//    std::vector<double> ptsx = {0.0};
//    std::vector<double> ptsy = {0.0};
//    double px = 0.0;
//    double py = 0.0;
//    double psi = 0.0;
//    double v = 0.0;
//    double delta= 0.0;
//    double a = 0.0;
//    /*
//        TODO: Calculate steering angle and throttle using MPC.
//        Both are in between [-1, 1].
//    */
//    cout << "MPC Started" <<endl;
//    double steer_value;
//    double throttle_value;
//    const double dT = 0.1;
//    const double Lf = 2.67;
//    size_t n = ptsx.size(); //number of way points
//        
//    Eigen::VectorXd ptsx_new = Eigen::VectorXd(n);
//    Eigen::VectorXd ptsy_new = Eigen::VectorXd(n); 
//    for(unsigned int i = 0 ; i < n ; i++){
//      const double dx = ptsx[i] - px; 
//      const double dy = ptsy[i] - py; 
//      ptsx_new[i] = dx* cos(-psi) - dy* sin(-psi);
//      ptsy_new[i] = dx* sin(-psi) + dy* cos(-psi);
//    }
//    // fit the plynomoial
//    auto coeffs = polyfit(ptsx_new,ptsy_new,3);        
//        
//    // Initial state.
//          /*
//          const double x0 = 0;
//          const double y0 = 0;
//          const double psi0 = 0;
//          const double cte0 = coeffs[0];
//          const double epsi0 = -atan(coeffs[1]);
//          */
//
//    //from lecture.
//    double x = 0;
//    double y = 0;
//    // TODO: calculate the cross track error
//    double cte = polyeval(coeffs, 0);
//    // TODO: calculate the orientation error
//    double epsi = -atan(coeffs[1]);
//
//
//    // Kinematic model is used to predict vehicle state at the actual
//    // moment of control (current time + delay dt)
//
//    // State after delay.
//    double x_next = x+ v * dT ; //sin(0) yields 1
//    double y_next = y ; //cos(0) yeilds zero, ultimately y_next is zero always 
//    double psi_next = -((v*delta*dT) / Lf);
//    double v_next = v + a * dT;
//    double cte_next = cte + (v*sin(epsi)*dT );
//    double epsi_next = epsi - (v* delta * dT / Lf );        
//          
//    // Define the state vector.
//    Eigen::VectorXd state(6);
//    state << x_next, y_next, psi_next, v_next, cte_next, epsi_next;
//
//    // Find the MPC solution.
//    //cout << "Calling MPC Solver" <<endl;
//    auto vars = mpc.Solve(state, coeffs);
//
//    steer_value = vars[0]/(deg2rad(25)*Lf);
//    throttle_value = vars[1];
//
//    //Display the waypoints/reference line
//    //vector<double> next_x_vals;
//    //vector<double> next_y_vals;
//    // NOTE: Remember to divide by deg2rad(25) before you send the steering value back.
//    // Otherwise the values will be in between [-deg2rad(25), deg2rad(25] instead of [-1, 1].
//
//    //Display the MPC predicted trajectory 
//    std::vector<double> mpc_x_vals;
//    std::vector<double> mpc_y_vals;
//
//    for (unsigned int i = 2; i < vars.size(); i++ ) {
//        if(i%2==0){
//            mpc_x_vals.push_back(vars[i]);
//        }
//        else {
//            mpc_y_vals.push_back(vars[i]);
//        }
//    }
//
//    //Display the waypoints/reference line
//    std::vector<double> next_x_vals;
//    std::vector<double> next_y_vals;
//    
//    // add (x,y) points to list here, points are in reference to the vehicle's coordinate system
//    // the points in the simulator are connected by a Green line
//         
//    double poly_inc = 2.5;
//    int num_points = 25;
//    for (int i = 1; i < num_points; i++ ) {
//      next_x_vals.push_back( poly_inc * i);
//      next_y_vals.push_back( polyeval(coeffs, poly_inc * i));
//    }
//
//
//    //.. add (x,y) points to list here, points are in reference to the vehicle's coordinate system
//    // the points in the simulator are connected by a Yellow line
//    // Latency
//    // The purpose is to mimic real driving conditions where
//    // the car does actuate the commands instantly.
//    //
//    // Feel free to play around with this value but should be to drive
//    // around the track with 100ms latency.
//    //
//    // NOTE: REMEMBER TO SET THIS TO 100 MILLISECONDS BEFORE
//    // SUBMITTING.*/
//    this_thread::sleep_for(chrono::milliseconds(100));
//    return 0;
}