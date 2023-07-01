#include "util.hpp"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const real infinity = std::numeric_limits<real>::infinity();
const real pi = 3.1415926535897932385;
constexpr real eps = 0.001;

inline real degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline real random_real() {
    return rand() / (RAND_MAX + 1.0);
}

inline real random_real(real min, real max) {
    return min + (max-min) * random_real();
}

inline real clamp(real x, real t_min, real t_max) {
    if (x < t_min) {
        return t_min;
    } if (x > t_max) {
        return t_max;
    }
    return x;
}

inline int random_int(int min, int max) {
    return static_cast<int>(random_real(min, max+1));
}

inline vec3 unit_vector(const vec3 &v) {
    return v / glm::length(v);
}

inline vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3(random_real(), random_real(), random_real());
        if(glm::dot(p,p) >= 1) continue;
        return p;
    }
}

inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

inline vec3 random_in_hemisphere(const vec3& normal) {
    vec3 in_unit_sphere = random_in_unit_sphere();
    if (glm::dot(in_unit_sphere, normal) > 0.0) 
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2 * glm::dot(v,n) * n;
}

inline vec3 refract(const vec3& v, const vec3& n, const real etai_over_etat) {
    auto cos_t = fmin(dot(-v, n), 1.0);
    vec3 perp = etai_over_etat * (v + cos_t * n);
    vec3 para = -sqrt(fabs(1 - glm::dot(perp, perp))) * n;
    return perp + para;
}

inline vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_real(-1,1), random_real(-1,1), 0);
        if (glm::dot(p,p) >= 1) continue;
        return p;
    }
}

inline constexpr bool near_zero(const vec3& v) {
    return glm::dot(v, v) < eps * eps;
}
