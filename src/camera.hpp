#include "util.hpp"

class camera {
    public: 
        camera (
            point3 source, 
            point3 target,
            vec3 view_up,
            double view_fov, 
            double aspect_ratio,
            double aperature, 
            double focus_dist
        ) {
            auto theta = degree_to_radians(view_fov);
            auto h = tan(theta/2);
            auto viewport_height = 2 * h;
            auto viewport_width = aspect_ratio * viewport_height;

            w = unit_vector(source - target);
            u = unit_vector(glm::cross(view_up, w));
            v = unit_vector(glm::cross(w, u));

            origin = source;
            horizontal = u * viewport_width;
            vertical = v * viewport_height;
            lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;
            lens_radius = aperature / 2;
        }

        ray get_ray(double s, double t) const { 
            vec3 rd = lens_radius * random_in_unit_disk();
            vec3 offset = u * rd.x() + v * rd.y();
            return ray(
                origin + offset,
                lower_left_corner + s*horizontal + t*vertical - origin - offset
            );
        }
    private: 
        point3 origin;
        point3 lower_left_corner;
        vec3 u;
        vec3 v;
        vec3 w;
        vec3 vertical;
        vec3 horizontal;
        double lens_radius;
}