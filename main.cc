#include <csignal>
#include <memory>

#include "simple_joint_controller.h"

namespace {
volatile std::sig_atomic_t g_signal = 0;
}

// This part is an example for usage of the controller,
// just skip reviewing the codes
int main() {
  std::signal(SIGINT, [](int signal) { g_signal = signal; });
  std::unique_ptr<Controller> controller =
      std::make_unique<SimpleJointController>();
  while (!g_signal) {
    // In fact, the p & v should fetch from sensor
    double fake_joint_position = 0.0;
    double fake_joint_velocity = 0.0;

    controller->Fresh(fake_joint_position, fake_joint_velocity);
    controller->Update();
    double action;
    controller->GetAction(&action);
    // Apply action to  actuator
  }
}