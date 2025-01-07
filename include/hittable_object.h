#ifndef HITTABLE_OBJECT_H
#define HITTABLE_OBJECT_H

enum EHittableObjectType {
    sphere,
    plane
};

class HittableObject { 
    
    public:
        virtual ~HittableObject() = default;
        EHittableObjectType object_type;
        void SetObjectType( EHittableObjectType type ) { this->object_type = type; }    

};

#endif