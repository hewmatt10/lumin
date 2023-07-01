#include <math.h>
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

#include <glm/glm.hpp>

#if USE_FLOATS
using real = float;
using vec3 = glm::vec3;
#else 
using real = double;
using vec3 = glm::dvec3;
#endif

using point3 = vec3;
using color = vec3;

inline vec3 unit_vector(const vec3 &v);

inline vec3 random_in_unit_sphere();

vec3 random_unit_vector();

vec3 random_in_hemisphere(const vec3& normal);

vec3 reflect(const vec3& v, const vec3& n);

vec3 refract(const vec3& v, const vec3& n, const double etai_over_etat);

vec3 random_in_unit_disk();