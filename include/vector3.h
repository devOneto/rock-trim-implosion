#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3 {

  public:

    using point3 = Vector3;

    double x;
    double y;
    double z;

    Vector3();
    Vector3(double x, double y, double z);


    Vector3& operator *= ( double t );
    Vector3& operator /= ( double t );
    Vector3& operator += ( const Vector3& );
    Vector3& operator -= ( const Vector3& );

    Vector3 unit( ) const;
    double length() const;
    double length_squared() const;

    Vector3 operator * ( double t ) const;
    Vector3 operator / ( double t ) const;
    Vector3 operator + ( const Vector3& u ) const;
    Vector3 operator - ( const Vector3& u ) const;

    static double dot( const Vector3& u, const Vector3& v );
    static Vector3 cross( const Vector3& u, const Vector3& v);

};

std::ostream& operator<<( std::ostream& os, const Vector3& v );

#endif