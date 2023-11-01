#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;

        // Sets the hit record normal vector. The parameter `outward_normal` is assumed to have unit length
        void set_face_normal(const ray &r, const vec3 &outward_normal) {
            this->front_face = r.direction().dot(outward_normal) < 0;
            this->normal = this->front_face ? outward_normal : - outward_normal; 
        }
}

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(ray &r, double r_tmin, double r_tmax, double r_tmin, hit_record &rec) const = 0;
};

#endif