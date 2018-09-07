#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"
#include "Exception.h"

namespace zxcLib
{
template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;

    T* array_copy(T* array,int ori_length,int dst_length)
    {
        T* ret = new T[dst_length];

        if(NULL != array)
        {
            int len = ori_length > dst_length ? ori_length : dst_length;

            for(int i = 0;i < len; i ++)
            {
                ret[i] = array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough menory for array copy...");
        }

        return ret;
    }

    void array_update(T* array,int length)
    {
        if(NULL != array)
        {
            T* temp = this->m_array;
            this->m_array = array;
            this->m_length = length;

            delete [] temp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough menory for array update...");
        }

    }

    void array_init(T* array,int length)
    {
        if(NULL != array)
        {
            this->m_array = array;
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for dynamic array ...");
        }
    }

public:
    DynamicArray(int length = 0 )    //申请空间
    {

        array_init(new T[length],length);


//        this->m_array = new T[length];

//        if(NULL != this->m_array)
//        {
//            m_length = length;
//        }
//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for dynamic array ...");
//        }
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
        array_init(array_copy(obj.m_array,obj.length(),obj.length()),obj.length());

//        this->m_array = new T[obj.length()];

//        if(NULL != this->m_array)
//        {
//            m_length = obj.length();

//            for(int i=0;i < m_length;i ++)
//            {
//                this->m_array[i] = obj.m_array[i];
//            }
//        }
//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for dymaic array ...");
//        }
    }

    DynamicArray<T> & operator =(const DynamicArray<T>& obj)
    {
        if(this != obj)
        {

            array_update(array_copy(obj.m_array,obj.length(),obj.length()),obj.length());

//            T* array = new T[obj.length()];

//            if(NULL != this->m_array)
//            {
//                for(int i = 0;i < obj.length();i ++)
//                {
//                    array[i] = obj.m_array[i];
//                }

//               T* temp = this->m_array;
//               this->m_array = array;
//               this->m_length = obj.length();

//               delete [] temp;

//            }
//            else
//            {
//                THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for dymaic array ...");
//            }

            return *this;

        }

    }


    int length() const
    {
        return m_length;
    }

    void resize(int length)
    {
        if(length != m_length)
        {

              array_update(array_copy(this->m_array,this->m_length,length),length);
//            T *array = new T[length];

//            if(NULL != array)
//            {
//                int temp_length = length > m_length ? m_length : length;

//                for(int i = 0; i < temp_length;i ++)
//                {
//                    array[i] = this->m_array[i];
//                }
//                T *temp = this->m_array;

//                this->m_length = length;

//                this->m_array = array;

//                delete [] temp;
//            }
//            else
//            {
//                THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for resize dynamic array ...");
//            }
        }
    }

    ~DynamicArray()
    {
        delete [] this->m_array;
    }


};

}
#endif // DYNAMICARRAY_H
