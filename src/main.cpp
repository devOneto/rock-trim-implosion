#include <iostream>
#include "color.h"
#include "vector3.h"

int main() {
    
    // Image

    int img_width = 256;
    int img_height = 256;

    // Render

    std::cout << "P3\n" << img_width << ' ' << img_height << '\n' << "255\n";

    for( int j = 0; j < img_height; j++ ) {

        std::clog << "/rScanlines remaning: " << (img_height - j) << '\n' << std::flush;

        for ( int i = 0; i < img_width; i++ ) {

            Color* pixel_color = new Color();
            pixel_color->r = double(i) / (img_width - 1);
            pixel_color->g = double(j) / (img_height - 1);
            pixel_color->b = 0;

            std::cout << pixel_color->write();

        }
    }

    std::clog << "\r Done. \n";

}