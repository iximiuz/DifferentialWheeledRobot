#ifndef DWR_ROBOT_H
#define DWR_ROBOT_H

#include "body.hpp"

class Robot {
private:
    Body bbox_;
    float wheel_radius_;
    float ang_vel_l_;
    float ang_vel_r_;

public:
    Robot(float width, float height, float x, float y, float wheel_radius) 
        : bbox_(Body(width, height, x, y)),
          wheel_radius_(wheel_radius), 
          ang_vel_l_(0.0), 
          ang_vel_r_(0.0) {}
};

#endif // DWR_ROBOT_H

