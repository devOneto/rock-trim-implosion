#ifndef SPHERE_H
#define SPHERE_H

#include <vector3.h>
#include "hittable_object.h"

class Sphere : public HittableObject {

  public:

    double radius;
    Vector3 center;
        
    Sphere() {
      SetObjectType( EHittableObjectType::sphere );
    }

    Sphere( Vector3 center, double radius ) : Sphere() {
      this->center = center;
      this->radius = radius;
    }

};

#endif