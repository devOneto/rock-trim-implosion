#include <iostream>
#include "ray.h"
#include "color.h"

Color _get_ray_color_sky_gradient( Ray ray ) {
    double a = ( ray.direction.unit().y + 1 ) * 0.5;
    double r = (1 - a) + a * 0.5;
    double g = (1 - a) + a * 0.7;
    double b = (1 - a) + a * 1.0;
    return Color(r, g, b); 
}

int main() {
    
    // Image

    int img_width, img_height;
    double aspect_ratio = 16.0 / 9.0;

    img_width = 400;
    img_height = int( img_width / aspect_ratio );
    img_height = img_height < 1 ? 1 : img_height;

    // Camera

    Vector3 camera_center = Vector3(0,0,0);

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * double(img_width / img_height);

    Vector3 viewport_u = Vector3 ( viewport_width, 0, 0);
    Vector3 viewport_v = Vector3 ( 0, -viewport_height, 0); 

    Vector3 viewport_delta_u = viewport_u / viewport_width;
    Vector3 viewport_delta_v = viewport_v / viewport_height;

    Vector3 focal_direction = Vector3(0, 0, focal_length);

    Vector3 viewport_upper_left = camera_center - focal_direction - viewport_v/2 - viewport_u/2;
    Vector3 viewport_upper_left_center = viewport_upper_left + ( viewport_delta_u + viewport_delta_v ) * 0.5 ;

    // Render

    std::cout << "P3\n" << img_width << ' ' << img_height << '\n' << "255\n";

    for( int j = 0; j < img_height; j++ ) {

        std::clog << "/rScanlines remaning: " << (img_height - j) << '\n' << std::flush;

        for ( int i = 0; i < img_width; i++ ) {

            Vector3 pixel_center = viewport_upper_left_center + viewport_delta_u * i + viewport_delta_v * j;
            Vector3 ray_direction = pixel_center - camera_center; // TODO: test using a unit vector, it's fancier

            Ray pixel_ray = Ray( camera_center, ray_direction );
            Color pixel_color = _get_ray_color_sky_gradient( pixel_ray );

            // Color* pixel_color = new Color();
            // pixel_color->r = double(i) / (img_width - 1);
            // pixel_color->g = double(j) / (img_height - 1);
            // pixel_color->b = 0;

            std::cout << pixel_color.write();

        }
    }

    std::clog << "\r Done. \n";

}