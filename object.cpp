#include "Object.h"
#include <cstdlib>
#include <iostream>
using namespace std;

namespace zxcLib {

void* Object::operator new (size_t size) throw()
{
    cout<<"Object::operator new"<<endl;
    return malloc(size);

}

void Object::operator delete(void* p)
{
    cout<<"Object::operator delete"<<endl;
    free(p);
}

void* Object::operator new[](size_t size) throw()
{
    cout<<"Object::operator new[]"<<endl;
    return malloc(size);
}

void Object::operator delete[](void* p)
{
    cout<<"Object::operator delete[]"<<endl;
    free(p);
}

bool Object::operator ==(const Object& obj)
{
    return (this == &obj);
}

bool Object::operator !=(const Object& obj)
{
    return (this != &obj);
}

Object::~Object()
{

}

}

