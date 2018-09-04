#include "SeqList.h"

using namespace zxcLib;

bool SeqList<T>::get(int i,T& e) const
{
    bool ret = ((0 <= i) && (i < m_length));

    if(ret)
    {
        e = m_array[i];
    }

    return ret;

}


bool SeqList<T>::set(int i,const T& e)
{
    bool ret = ((0 <= i) && (i < m_length));

    if(ret)
    {
        m_array[i] = e;
    }

    return ret;

}

bool SeqList<T>::insert(int i,const T& e)
{
    bool ret = ((0 <= i) && (i <= m_length));

    ret = ret &&((m_length + 1) < capacity());

    if(ret)
    {

    }
    if(ret)
    {
        for(int p = m_length-1;p >= i ;p--)
        {
            m_array[p+1] = m_array[p];
        }
        m_array[i] = e;
        m_length++;
    }
//    {
//      for(int p = i;p < m_length +1;p++)
//      {
//          m_array[p+1] = m_array[p];
//      }
//      m_array[i] = e;
//      m_length++;
//    }

     return ret;
}

bool SeqList<T>::remove(int i)
{
    bool ret = ((0 <= i) && (i <= m_length));

    if(ret)
    {
       for(int p = i;p < m_length-1;p++)
       {
           m_array[p] = m_array[p+1];
       }

       m_length--;
    }

    return ret;
}
