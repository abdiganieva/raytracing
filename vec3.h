#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
	public:
		double e[3] = {0, 0, 0};
		
		vec3() = default;
		vec3(double e0, double e1, double e2): e{e0, e1, e2} {}
		
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }
		
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		double operator[](std::size_t i) const { return e[i]; }
		double& operator[](std::size_t i) { return e[i]; }
		
		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		
		vec3& operator-=(const vec3 &v) {
			e[0] -= v.e[0];
			e[1] -= v.e[1];
			e[2] -= v.e[2];
			return *this;
		}
		
		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}
		
		vec3& operator/=(double t) {
			return * this *= 1 / t;
		}
		
		double length() const {
			return std::sqrt(length_squared());
		}

		double dot(const vec3& u) const {
			return e[0] * u.e[0] + e[1] * u.e[1] + e[2] * u.e[2];
		}
		
		double length_squared() const {
			return dot(*this);
		}
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(vec3 u, const vec3 &v) {
	return (u += v);
}

inline vec3 operator-(vec3 u, const vec3 &v) {
	return (u -= v);
}

inline vec3 operator*(const vec3 &v, double t) {
	return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(double t, const vec3 &v) {
	return v * t;
}

inline vec3 operator/(vec3 v, double t) {
	return v /= t;
}

inline vec3 operator*(const vec3 &v, const vec3 &u) {
	return vec3(v.e[0] * u.e[0], v.e[1] * u.e[1], v.e[2] * u.e[2]);
}

inline vec3 unit_vector(const vec3 v) {
	return v / v.length();
}

inline double dot(const vec3 v, const vec3 u) {
	return v.dot(u);
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

#endif
