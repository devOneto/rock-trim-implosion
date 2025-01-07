#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {

  public:

    float r; 
    float g; 
    float b;
    float a;
    
    Color() : Color( 0, 0, 0, 1.0f ){}
    Color( float r, float g, float b) : r(r), g(g), b(b), a(1.0f) {}
    Color( float r, float g, float b, float a ) : r(r), g(g), b(b), a(a) {}

    Color operator * ( double t ) const {
        return Color( this->r * t, this->g * t, this->b * t );
    }

    std::string write( ){
      int r_byte = this->r * 255.999;
      int g_byte = this->g * 255.999;
      int b_byte = this->b * 255.999;
      return std::to_string(r_byte) + " " + std::to_string(g_byte) + " " + std::to_string(b_byte) + " " + '\n';
    }

};

#endif