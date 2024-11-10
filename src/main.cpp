#include <SDL2/SDL.h>
#include <iostream>
#include "ray.h"
#include "color.h"
#include "sphere.h"

int main() {
    
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        std::cerr << "Error initializating SDL: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Rock Trim Implosion",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    if ( window == nullptr ) {
        std::cerr << "Error opening the window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 0;
    }

    bool is_running = true;
    SDL_Event event;

    while ( is_running ) {

        while(SDL_PollEvent(&event)) {
            if( event.type == SDL_QUIT ) {
                is_running = false;
            }
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

    // Image

    int img_width, img_height;
    double aspect_ratio = 16.0 / 9.0;

    img_width = 400;
    img_height = int( img_width / aspect_ratio );
    img_height = (img_height < 1) ? 1 : img_height;

    // Camera

    Vector3 camera_center = Vector3(0,0,0);

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(img_width) / img_height);

    Vector3 viewport_u = Vector3 ( viewport_width, 0, 0);
    Vector3 viewport_v = Vector3 ( 0, -viewport_height, 0); 

    Vector3 pixel_delta_u = viewport_u / img_width;
    Vector3 pixel_delta_v = viewport_v / img_height;

    Vector3 focal_direction = Vector3(0, 0, focal_length);

    Vector3 viewport_upper_left = camera_center - focal_direction - viewport_u/2 - viewport_v/2;
    Vector3 viewport_upper_left_center = viewport_upper_left + ( pixel_delta_u + pixel_delta_v ) * 0.5 ;

    // Objects

    Sphere sphere = Sphere( Vector3(0, 0, -1), 0.5 );

    // Render

    std::cout << "P3\n" << img_width << ' ' << img_height << '\n' << "255\n";

    for( int j = 0; j < img_height; j++ ) {

        std::clog << "/rScanlines remaning: " << (img_height - j) << '\n' << std::flush;

        for ( int i = 0; i < img_width; i++ ) {

            Vector3 pixel_center = viewport_upper_left_center + (pixel_delta_u * i) + (pixel_delta_v * j);
            Vector3 ray_direction = pixel_center - camera_center; // TODO: test using a unit vector, it's fancier

            Ray pixel_ray = Ray( camera_center, ray_direction );
            Color pixel_color = pixel_ray.get_color( sphere );

            std::cout << pixel_color.write();

        }
    }

    std::clog << "\r Done. \n";

}