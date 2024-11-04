#include "ray.h"
#include <cmath>

Ray::Ray() {};
Ray::Ray( const Vector3& origin, const Vector3& direction ) : origin(origin), direction(direction) {}

/** Returns a point3 along of the ray in function of t. Meaning: P(t) = origin + direction * t */
Vector3 Ray::at( double t ) {
    return ( this->direction * t ) + this->origin;
}

double Ray::hit_sphere ( Sphere sphere ) {
    
    Vector3 oc = sphere.center - this->origin;

    double a = Vector3::dot( this->direction, this->direction );
    double b = -2.0 * Vector3::dot( this->direction, oc );
    double c = Vector3::dot(oc, oc) - sphere.radius * sphere.radius;
    double d = b*b - 4 * a * c;

    if ( d < 0 ) return -1;
    return ( (-b - std::sqrt(d)) / 2.0 * a );

}

Color Ray::get_color( Sphere sphere ) {

    double hit_sphere_intensity = this->hit_sphere(sphere);

    if ( hit_sphere_intensity > 0 ) {
        Vector3 normal = ( this->at(hit_sphere_intensity) - Vector3(0,0,-1) );
        return Color( normal.x + 1, normal.y + 1, normal.z + 1) * 0.5;
    }

    double a = 0.5 * ( 1.0 + this->direction.unit().y );
    double r = (1 - a) + (a * 0.5);
    double g = (1 - a) + (a * 0.7);
    double b = (1 - a) + (a * 1.0);
    return Color(r, g, b); 
}