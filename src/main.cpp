#include <SDL2/SDL.h>
#include <iostream>
#include "ray.h"
#include "color.h"
#include "sphere.h"

int main() {
    
    // Image

    int img_width, img_height;
    double aspect_ratio = 4.0 / 3.0;

    img_width = 800;
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

    Sphere* sphere = new Sphere( Vector3(-.5, 0, -1), 0.5 );
    Sphere* sphereB = new Sphere( Vector3(.5, 0, -1), 0.5 );

    // SDL

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow(
        "Rock Trim Implosion",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        img_width,
        img_height,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        img_width,
        img_height
    );

    Uint32* pixels = new Uint32[ img_width * img_height ];

    bool is_running = true;
    SDL_Event event;

    while ( is_running ) {

        while(SDL_PollEvent(&event)) {
            if( event.type == SDL_QUIT ) {
                is_running = false;
            }
        }

        for( int j = 0; j < img_height; j++ ) {
            for ( int i = 0; i < img_width; i++ ) {

                Vector3 pixel_center = viewport_upper_left_center + (pixel_delta_u * i) + (pixel_delta_v * j);
                Vector3 ray_direction = pixel_center - camera_center;

                Ray pixel_ray = Ray( camera_center, ray_direction );
                Color pixel_color = pixel_ray.get_color( {sphere, sphereB} );

                //TODO
                pixel_color.r *= 255.999;
                pixel_color.g *= 255.999;
                pixel_color.b *= 255.999;
                pixel_color.a *= 255.999;

                pixels[j * img_width + i] = ((int)pixel_color.r << 24) | ((int)pixel_color.r << 16) | ((int)pixel_color.b << 8) ;

            }
        }

        SDL_UpdateTexture(texture, nullptr, pixels, img_width * sizeof(Uint32));

        SDL_RenderClear( renderer );
        SDL_RenderCopy( renderer, texture, nullptr, nullptr );
        SDL_RenderPresent( renderer );

    }

    // Limpa memória e encerra o SDL
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}