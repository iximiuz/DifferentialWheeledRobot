#ifndef DWR_BODY_H
#define DWR_BODY_H

#include "vec.hpp"

class Body {
private:
    float width_;
    float height_;
    Vec2 center_;
    float angle_;

public: 
    Body(float width, float height, float x, float y, float angle = 0.0) 
        : width_(width), height_(height), center_(x, y), angle_(angle) {}

    inline float GetWidth() const { return width_; }
    inline float GetHeight() const { return height_; }
};

#endif // DWR_BODY_H

