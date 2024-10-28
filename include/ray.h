#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
  
  public:

    Vector3 origin;
    Vector3 direction;

    Ray();
    Ray( const Vector3& origin, const Vector3& direction );

    Vector3 at( double t );

};

#endif