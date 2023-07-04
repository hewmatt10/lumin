#include "util.hpp"

class ray{
    public:
        constexpr ray() = default;
        constexpr ray (const point3& o, const vec3& dir) :  origin(o), direction(dir);
        constexpr inline point3 at(const real t) { return origin + t * direction; }
        constexpr inline point3 origin() { return origin; }
        constexpr inline vec3 direction() {return direction; }
    private: 
        point3 origin = point3(0.0, 0.0, 0.0);
        vec3 direction = vec3(0.0, 1.0, 0.0);

}