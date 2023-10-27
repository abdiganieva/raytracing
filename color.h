#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0, 255] value to std output
    out << static_cast<int>(255.999 * pixel_color.x()) << ' ' <<  static_cast<int>(255.999 * pixel_color.y()) << ' ' << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif