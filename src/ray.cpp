#include "ray.h"

Ray::Ray() {};
Ray::Ray( const Vector3& origin, const Vector3& direction ) : origin(origin), direction(direction) {}

/** Returns a point3 along of the ray in function of t. Meaning: P(t) = origin + direction * t */
Vector3 Ray::at( double t ) {
    return ( this->direction * t ) + this->origin;
}

Color Ray::get_color() {
    double a = 0.5 * ( 1.0 + this->direction.unit().y );
    double r = (1 - a) + (a * 0.5);
    double g = (1 - a) + (a * 0.7);
    double b = (1 - a) + (a * 1.0);
    return Color(r, g, b); 
}