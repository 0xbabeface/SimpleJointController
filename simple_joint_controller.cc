#include "simple_joint_controller.h"

#include <iostream>

Controller::Controller() : iter_(0) {
  std::cout << "A controller is constructed." << std::endl;
}

Controller::~Controller() {
  std::cout << "A controller is destructed." << std::endl;
}

SimpleJointController::SimpleJointController() {}

// SimpleJointController::~SimpleJointController() {}

void SimpleJointController::Fresh(double joint_position,
                                  double joint_velocity) {
  current_joint_position_ = joint_position;
  current_joint_velocity_ = velocity_filter_.Filter(joint_velocity);
}

void SimpleJointController::Update() {
  if (iter_ == 0) { // iter_ is always 0, something is wrong?
    CubicBezier cb(10000); // magic number
    spline_ = cb.GetArray(current_joint_position_, 3.0); // magic number
  }
  double target_position = spline_[iter_];
  double target_velocity = 0.0;
  torque_ = 100.0 * (target_position - current_joint_position_) +
            1.0 * (target_velocity - current_joint_velocity_);
}

void SimpleJointController::GetAction(double *torque) { *torque = torque_; }