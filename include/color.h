#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {

  public:

    float r; 
    float g; 
    float b;
    float a;
    
    Color();
    Color(float, float, float);
    Color(float, float, float, float);

    std::string write( );

    Color operator * ( double t ) const;

};

#endif