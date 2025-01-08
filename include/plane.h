#ifndef PLANE_H
#define PLANE_H

#include "vector3.h"
#include "hittable_object.h"

class Plane : public HittableObject {

  public:

    Vector3 normal;
    Vector3 point_inside;

    Plane() {
        SetObjectType(EHittableObjectType::plane);
    }

    Plane( Vector3 normal, Vector3 point ): Plane() {
        this->normal = normal;
        this->point_inside = point;
    }

};

#endif