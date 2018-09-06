#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "Object.h"
#include "LinkList.h"

namespace zxcLib {

template<typename T,int N>
class StaticLinkList : public LinkList<T>
{
protected:
    int m_used[N];
    typedef typename LinkList<T>::Node Node;

    struct SNode : public Node
    {
        void* operator new(size_t  sz,void* loc)
        {
            return loc;
        }

        void operator delete(void* loc)
        {
            return;
        }
    };

    char m_space[sizeof(SNode) * N];

public:
    StaticLinkList()
    {
        for(int i = 0;i < N;i ++)
        {
            m_used[i] = 0;
        }
    }

    Node* create()
    {
        SNode* ret = NULL;
        int i = 0;
        for(i = 0;i < N;i ++)
        {
            if(0 == m_used[i])
            {
                ret = reinterpret_cast<SNode*>(&m_space) + i ;//[sizeof(SNode) * i]);
                ret = new(ret) SNode();
                m_used[i] = 1;
                break;
            }
        }

        cout << "Static Link List create" << endl;
        if(i < N)
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for create static linklist ...");
        }
    }

    int capation()
    {
        return N;
    }
    void destroy(int i)
    {
        if((i >= 0) && (i<N))
        {
            m_used[i] = 0;

            remove(i);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"Invalid parameter for destroy ...");
        }
    }

    void destroy(Node* delete_node = NULL)
    {

         if(NULL != delete_node)
         {
             SNode* destroy_node = dynamic_cast<SNode*>(delete_node);
             SNode* space = reinterpret_cast<SNode*>(m_space);
             int p = 0;
             if(sizeof(SNode) != 0)
             {
                 p = (reinterpret_cast<int>(destroy_node) - reinterpret_cast<int>(space)) / sizeof(SNode);
                 cout << "p:" << p << endl;
             }
             else
             {
                 THROW_EXCEPTION(InvalidParameterException,"Invalid parameter for destroy ...");
             }

             m_used[p] = 0;
             remove(delete_node);
         }
         else
         {
             THROW_EXCEPTION(InvalidParameterException,"Invalid parameter for destroy ...");
         }

    }

    ~StaticLinkList()
    {
       this->clean();
    }

};

}
#endif // STATICLINKLIST_H
