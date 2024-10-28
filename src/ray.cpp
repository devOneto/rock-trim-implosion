#include "ray.h"

Ray::Ray() {};
Ray::Ray( const Vector3& origin, const Vector3& direction ) : origin(origin), direction(direction) {}

/** Returns a point3 along of the ray in function of t. Meaning: P(t) = origin + direction * t */
Vector3 Ray::at( double t ) {
    return ( this->direction * t ) + this->origin;
}
