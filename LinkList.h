#ifndef LINKLIST_H
#define LINKLIST_H

#include "Object.h"
#include "Exception.h"

namespace zxcLib {

template <typename T>
class LinkList : public Object
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
        Node* previous;
    };

   mutable struct : public Object
    {
        char reserved[sizeof(T)];
        Node* next;
        Node* previous;
    } m_header;

    //mutable Node m_header;
    int m_length;
    Node* m_cur_node;
    int m_step;

    Node* get_position(int i) const
    {
        Node* cur_node = reinterpret_cast<Node*>(&m_header);//&m_header;

        for(int cnt = 0;cnt < i+1;cnt ++)
        {
            cur_node = cur_node->next;
        }

        return cur_node;
    }

    virtual Node* create()
    {
        return (new Node());
    }

    virtual void destroy(Node* delete_node)
    {
        delete delete_node;
    }

public:
//    LinkList()
//    {
//        m_header.next = NULL;
//        m_header.previous = NULL;
//        m_length = 0;

//    }

    LinkList()
    {
        m_header.next = NULL;
        m_header.previous = NULL;
        m_length = 0;

        m_cur_node = NULL;
        m_step = 0;

    }

    void add(T& e)
    {
         Node* new_node = create();//new Node();

         if(NULL != new_node)
         {            
             Node* cur_node = get_position(m_length-1);//&m_header;//reinterpret_cast<Node*>(&m_header);
             new_node->value = e;

//             while(NULL != cur_node->next)
//             {
//                 cur_node = cur_node->next;
//             }

             cur_node->next = new_node;
             new_node->next = NULL;
             new_node->previous = cur_node;

             m_length ++;
         }
         else
         {
             THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory for new node ...");
         }


    }

    bool set(int i,const T& e)
    {
        bool ret = ((0 <= i) && (i <= m_length));

        if(ret)
        {
//            Node* set_node = &m_header;//reinterpret_cast<Node*>(&m_header);
//            int cnt = 0;

//            while(cnt < i)
//            {
//                set_node = set_node->next;
//                cnt ++;
//            }

//            set_node->value = e;
            Node* set_node = get_position(i);
            set_node->value=e;
        }
//        else
//        {
//            THROW_EXCEPTION(InvalidParameterException,"Invalid parameter ...");
//        }

        return ret;



    }

    bool insert(int i,const T& e)
    {
        bool ret = ((0 <= i) && (i <= m_length));

        if(ret)
        {
            Node* new_node = create();//new Node;
            Node* insert_node = get_position(i);//&m_header;//reinterpret_cast<Node*>(&m_header);
            int cnt = 0;

            new_node->value = e;

//            while(cnt < i)
//            {
//                insert_node = insert_node->next;
//                cnt ++;
//            }

            insert_node->previous->next = new_node;
            new_node->previous = insert_node->previous;

            new_node->next = insert_node;
            insert_node->previous = new_node;

            m_length ++;

        }
//        else
//        {
//            THROW_EXCEPTION(InvalidParameterException,"Invalid parameter ...");
//        }

        return ret;


    }

    T& get(int i) const
    {
       bool ret = ((0 <= i) && (i <= m_length));

       if(ret)
       {
//           int cnt = 0;
//           Node* get_node = m_header.next;

//           while(cnt < i && (NULL != get_node))
//           {
//               get_node = get_node->next;
//               cnt ++;
//           }

//           return get_node->value;//m_header.next->value;
           Node* get_node = get_position(i);
           return get_node->value;
       }
       else
       {
           THROW_EXCEPTION(InvalidParameterException,"Invalid parameter ...");
       }

       //return NULL;
    }

    bool remove(int i)
    {
        bool ret = ((0 <= i) && (i <= m_length));

        if(ret)
        {
            int cnt = 0;
            Node* remove_node = get_position(i);//&m_header;//reinterpret_cast<Node*>(&m_header);

//            while(cnt < i)
//            {
//                remove_node = remove_node->next;
//                cnt ++;
//            }

            if(m_cur_node ==  remove_node)
            {
                m_cur_node = m_cur_node->next;
            }
            remove_node->previous->next = remove_node->next;
            remove_node->next->previous = remove_node->previous;

            m_length --;
            delete remove_node;

        }

        return ret;

    }

    bool remove(Node* p)
    {
        bool ret = (NULL != p);

        if(ret)
        {
            Node* remove_node;

            for(int i = 0;i < m_length;i ++)
            {
                if(p == get_position(i))
                {
                    remove(i);
                    break;
                }
            }

        }

        return ret;
    }

    int get_length()
    {
        return m_length;
    }

    int find(const T& e) const
    {
        Node* cur_node = m_header.next;
        int ret = -1;
        int cnt = 0;

        while(NULL != cur_node)
        {
            if(cur_node->value == e)
            {
                ret = cnt;
                break;
            }
            else
            {
                cur_node = cur_node->next;
                cnt ++;
            }
            cout << cnt << endl;
        }

        return ret;

    }

    void clean()
    {
        //int cnt = 0;
        Node* cur_node = m_header.next;
        Node* delete_node = m_header.next;

        while(NULL != cur_node)
        {
            m_length --;
            delete_node = cur_node;
            cur_node = cur_node->next;
            destroy(delete_node) ;
        }
    }

    bool move(int start = 0,int step = 1)
    {
        bool ret;

        ret = ((start >= 0) && (start < m_length) && (step > 0));

        if(ret)
        {
             m_cur_node = get_position(start);
             m_step = step;
        }
        else
        {
             THROW_EXCEPTION(IndexOutOfBoundsException,"Index out of linklist ...");
        }

         return ret;
    }

    bool end()
    {
        return (m_cur_node == NULL);
    }

    T& get_cur_node()
    {
        if(! end())
        {
            return (m_cur_node->value);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperatorException,"No value at current position ...");
        }

    }

    bool next()
    {
        int i = 0;
        
        for(i;i < m_step;i ++)
        {

            m_cur_node = m_cur_node->next;

            if(m_cur_node == NULL)
            {
                break;
            }

        }

        return (i == m_step);


    }

    Node* position(const int i)
    {
        return get_position(i);
    }

    ~LinkList()
    {
       clean();
    }
};
}

#endif // LINKLIST_H
