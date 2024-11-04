#ifndef RAY_H
#define RAY_H

#include "color.h"
#include "sphere.h"
#include "vector3.h"

class Ray {
  
  public:

    Vector3 origin;
    Vector3 direction;

    Ray();
    Ray( const Vector3& origin, const Vector3& direction );

    Color get_color( Sphere sphere );
    Vector3 at( double t );
    double hit_sphere( Sphere sphere );
};

#endif