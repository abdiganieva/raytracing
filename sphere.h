#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"

class sphere : public hittable {

    public:
        sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

    private:
        point3 center;
        double radius;

    bool hit(const ray &r, double r_tmin, double r_tmax, double r_tmin, hit_record &rec) const override {

        vec3 oc = r.origin() - this->center;
	    auto a = r.direction().length_squared();
	    auto half_b = oc.dot(r.direction());
	    auto c = oc.length_squared() - this->raduis * this->raduis;
	    auto discriminant = half_b *half_b - a * c;
	    if (discriminant < 0) return false;
        auto sqrt_discr = std::sqrt(discriminant);

        // Finding nearest root t that lies in the range t_min < t < t_max
        auto root = (-half_b - sqrt_discr) / a;
        if (root <= r_tmin || root >= r_tmax) {
            root = (-half_b + sqrt_discr) / a;
            if (root <= r_tmin || root >= r_tmax) return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - this->center) / this->radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }
    
}