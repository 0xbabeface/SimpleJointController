#include "average_filter.h"
#include "cubic_bezier.h"

class Controller {
public:
  Controller();
  ~Controller();
  virtual void Fresh(double joint_position, double joint_velocity) = 0;
  virtual void Update() = 0;
  virtual void GetAction(double *torque) = 0;

protected:
  int iter_;
};

class SimpleJointController : public Controller {
public:
  SimpleJointController();
  // ~SimpleJointController();
  void Fresh(double joint_position, double joint_velocity);
  void Update();
  void GetAction(double *torque);

private:
  vector<double> spline_;

  double current_joint_position_;
  double current_joint_velocity_;
  AverageFilter velocity_filter_;

  double torque_;
};