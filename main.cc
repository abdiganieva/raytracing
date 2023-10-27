#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


#include <cassert>

color ray_color(const ray &r) {
	vec3 unit_direction = unit_vector(r.direction());
	assert( std::abs(unit_direction.length() - 1.0) < 1e-15 );
	auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 0.0, 0.3) + a*color(0.8, 0.0, 1.0);
}

int main() {

	// Image
	auto aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// Calculating image height using aspect ratio and ensuring that it's at least 1
	int image_height = static_cast<int>(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	//Camera
	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
	auto camera_center = point3(0, 0, 0);

	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	// Horizontal and vertical delta pixels (distance between 2 pixels)
	auto u_delta = viewport_u / image_width;
	auto v_delta = viewport_v / image_height;

	// Viewport upper left pixel location
	auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;

	// Center of upper left pixel
	auto pixel00_loc = viewport_upper_left + 0.5 * (u_delta + v_delta);


	// Render
	
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	for (int j = 0; j < image_height; ++j) {
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			
			auto pixel_center_loc = pixel00_loc + (i * u_delta) + (j * v_delta);
			auto ray_direction = pixel_center_loc - camera_center;
			ray r = ray(camera_center, ray_direction);

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "All done!" << '\n';
}
