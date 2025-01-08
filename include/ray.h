#ifndef RAY_H
#define RAY_H

#include "color.h"
#include "hittable_object.h"
#include "plane.h"
#include "sphere.h"
#include "vector3.h"
#include <cmath>
#include <cstddef>
#include <vector>

class Ray {
  
  public:

    Vector3 origin;
    Vector3 direction;

    Ray() {};
    Ray( const Vector3& origin, const Vector3& direction ) : origin(origin), direction(direction) {}

    /** Returns a point3 along of the ray in function of t. Meaning: P(t) = origin + direction * t */
    Vector3 at( double t ) {
        return ( this->direction * t ) + this->origin;
    }

    double hit_sphere ( const Sphere* sphere ) {
        
        Vector3 oc = sphere->center - this->origin;

        double a = Vector3::dot( this->direction, this->direction );
        double b = -2.0 * Vector3::dot( this->direction, oc );
        double c = Vector3::dot(oc, oc) - sphere->radius * sphere->radius;
        double d = b*b - 4 * a * c;

        if ( d < 0 ) return -1;
        return ( (-b - std::sqrt(d)) / 2.0 * a );

    }

    double hit_plane( const Plane* plane ) {
        
        double dot_normal_direction = Vector3::dot(plane->normal, this->direction);

        if ( dot_normal_direction == 0 ) return -1;

        return Vector3::dot(plane->normal, plane->point_inside - this->origin) / dot_normal_direction;

    }

    Color get_color( std::vector<HittableObject*> objects ) {

        float t = 0;
        float last_t = 0;
        const HittableObject* last_t_object = nullptr;

        for( int i = 0; i < objects.size(); i++ ) {
            
            HittableObject* current_object = objects[i];

            switch ( current_object->object_type ) {

                case sphere: {
                    const Sphere* sphere = dynamic_cast<const Sphere*>(current_object);
                    t =  this->hit_sphere(sphere);
                    if( t > last_t ) last_t_object = sphere;
                    break;
                }
                case plane: {
                    const Plane* plane = dynamic_cast<const Plane*>(current_object);
                    t = this->hit_plane(plane);
                    if( t > last_t ) last_t_object = plane;
                    break;
                }

            }
        }

        if ( last_t_object == nullptr ) {
            double a = 0.5 * ( 1.0 + this->direction.unit().y );
            double r = (1 - a) + (a * 0.5);
            double g = (1 - a) + (a * 0.7);
            double b = (1 - a) + (a * 1.0);
            return Color(r, g, b);
        }

        Vector3 normal = ( this->at(last_t) - Vector3(0,0,-1) );
        return Color( normal.x + 1, normal.y + 1, normal.z + 1) * 0.5;
         
    }
};

#endif