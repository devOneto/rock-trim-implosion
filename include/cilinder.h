#ifndef CILINDER_H
#define CILINDER_H

#include "vector3.h"
#include "hittable_object.h"


class Cilinder : public HittableObject {

  public:
    
    double radius;
    Vector3 top_center;
    Vector3 bottom_center;

    Cilinder(){
        SetObjectType( EHittableObjectType::cilinder );
    }

    Cilinder( double radius, Vector3 top_center, Vector3 bottom_center ) : Cilinder() {
        this->radius = radius;
        this->top_center = top_center;
        this->bottom_center = bottom_center;
    }

};

#endif