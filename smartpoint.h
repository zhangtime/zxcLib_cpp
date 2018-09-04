#ifndef SMARTPOINT_H
#define SMARTPOINT_H

#include <iostream>
#include <string>
#include "object.h"

using namespace std;

namespace zxcLib {

template <typename T>
class SmartPoint : public Object
{
private:
    T* m_pointer;

public:
    SmartPoint(T* p = NULL)
    {
        m_pointer = p;
        cout << "SmartPoint(T* p = NULL)" << endl;
    }

    SmartPoint(const SmartPoint& obj)
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPoint&>(obj).m_pointer = NULL;
        cout << "SmartPoint(const SmartPoint& obj)" << endl;
    }

    T &operator =(SmartPoint &obj)
    {
        if(this != NULL)
        {
            m_pointer = obj.m_pointer;
            const_cast<SmartPoint&>(obj).m_pointer = NULL;
        }
        return this;
    }

    T *operator ->()
    {
        return  m_pointer;
    }

    T &operator *()
    {
        return *m_pointer;
    }

    bool is_null()
    {
        return (m_pointer == NULL);
    }

    ~SmartPoint()
    {
        cout << "SmartPoint delete" <<endl;
        delete m_pointer;
    }
};

}


#endif // SMARTPOINT_H
