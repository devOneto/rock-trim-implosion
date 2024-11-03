#include "ray.h"

Ray::Ray() {};
Ray::Ray( const Vector3& origin, const Vector3& direction ) : origin(origin), direction(direction) {}

/** Returns a point3 along of the ray in function of t. Meaning: P(t) = origin + direction * t */
Vector3 Ray::at( double t ) {
    return ( this->direction * t ) + this->origin;
}

bool Ray::hit_sphere ( Sphere sphere ) {
    
    Vector3 oc = sphere.center - this->origin;

    double a = Vector3::dot( this->direction, this->direction );
    double b = -2.0 * Vector3::dot( this->direction, oc );
    double c = Vector3::dot(oc, oc) - sphere.radius * sphere.radius;
    double d = b*b - 4 * a * c;

    return ( d >= 0 );

}

Color Ray::get_color( Sphere sphere ) {

    if ( this->hit_sphere(sphere) )
        return Color(1,0,0);

    double a = 0.5 * ( 1.0 + this->direction.unit().y );
    double r = (1 - a) + (a * 0.5);
    double g = (1 - a) + (a * 0.7);
    double b = (1 - a) + (a * 1.0);
    return Color(r, g, b); 
}