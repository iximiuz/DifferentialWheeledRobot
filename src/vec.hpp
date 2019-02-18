#ifndef DWR_VEC_H
#define DWR_VEC_H

#include <iostream>

class Vec2 {
private:
    float x_, y_;

public: 
    Vec2(float x, float y) : x_(x), y_(y) {}

    inline float GetX() const { return x_; }
    inline float GetY() const { return y_; }
};

std::ostream& operator<<(std::ostream& s, const Vec2& v);

#endif // DWR_VEC_H

