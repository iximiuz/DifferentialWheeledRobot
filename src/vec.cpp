#include "vec.hpp"

std::ostream& operator<<(std::ostream& s, const Vec2& v) {
    return s << "Vec2{" << v.GetX() << ", " << v.GetY() << "}";
}

