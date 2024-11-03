#include <cmath>
#include "vector3.h" 

Vector3::Vector3( ) : Vector3(0,0,0) {} 
Vector3::Vector3( double x, double y, double z ) : x(x), y(y), z(z) {}

Vector3 Vector3::operator + ( const Vector3& u ) const {
    return Vector3( this->x + u.x, this->y + u.y, this->z + u.z );
} 

Vector3 Vector3::operator - ( const Vector3& u ) const {
    return Vector3( this->x - u.x, this->y - u.y, this->z - u.z );
}

Vector3 Vector3::operator * ( double t ) const {
    return Vector3( this->x * t, this->y * t, this->z * t );
}

Vector3 Vector3::operator / ( double t ) const {
    return Vector3( this->x / t, this->y / t, this->z / t );
}

Vector3& Vector3::operator += ( const Vector3& u ) {
    this->x += u.x;
    this->y += u.y;
    this->z += u.z;
    return *this;
}

Vector3& Vector3::operator -= ( const Vector3& u ) {
    this->x -= u.x;
    this->y -= u.y;
    this->z -= u.z;
    return *this;
}

Vector3& Vector3::operator *= ( double t ) {
    this->x *= t;
    this->y *= t;
    this->z *= t;
    return *this;
}

Vector3& Vector3::operator /= ( double t ) {
    return *this *= 1/t;
}

double Vector3::length() const {
    return std::sqrt(this->length_squared());
}

double Vector3::length_squared() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}

Vector3 Vector3::unit( ) const {
    return *this / this->length();
}

double Vector3::dot( const Vector3& u, const Vector3& v ) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3 Vector3::cross( const Vector3& u, const Vector3& v ) {
    return Vector3( 
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}

std::ostream& operator << ( std::ostream& os, const Vector3& v ) {
    return os << v.x << ' ' << v.y << ' ' << v.z;
}