#ifndef SPHERE_H
#define SPHERE_H

#include <vector3.h>

class Sphere {

  public:

    double radius;
    Vector3 center;
    
    Sphere();
    Sphere( Vector3 center, double radius );


};

#endif