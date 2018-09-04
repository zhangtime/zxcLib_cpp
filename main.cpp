#include <QCoreApplication>
#include "Exception.h"
#include "Object.h"
#include "SmartPoint.h"
#include "List.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "Dynamicarray.h"
#include "LinkList.h"
#include "StaticLinkList.h"

using namespace std;
using namespace zxcLib;

class test : public Object
{
protected:
    int cnt;
public:
//    test1()
//    {
//        cnt = 0;
//    }
    test(int i = 0)
    {
        cnt = i;
    }

    bool operator ==(const test& obj)
    {
        return (cnt == obj.cnt);
    }

    bool operator !=(const test& obj)
    {
        return (cnt != obj.cnt);
    }
};

int main(int argc, char *argv[])
{

    StaticLinkList<int,9> linklist_test;

//    cout << "find num:"<<find << endl;

    //LinkList<int> linklist_test;

    for(int i = 0;i < 6;i ++)
    {
        linklist_test.add(i);
    }

    cout << "-----------------------------" << endl;
    for(linklist_test.move(0,1);!linklist_test.end();linklist_test.next())
    {
        cout << linklist_test.get_cur_node() << endl;
    }

    cout << "-----------------------------" << endl;

    linklist_test.set(1,7);
    linklist_test.insert(1,10);

    //linklist_test.destroy(1);
    linklist_test.destroy(linklist_test.position(3));
    //int find;
    //linklist_test.find(find,5);

    //cout << "find num:"<<find << endl;

    for(int i = 0;i < linklist_test.get_length();i ++)
    {
        cout << linklist_test.get(i) << endl;
    }
    //linklist_test.destroy(-1,linklist_test.position(2));

    cout << "-----------------------------" << endl;
    linklist_test.remove(2);
    for(int i = 0;i < linklist_test.get_length();i ++)
    {
        cout << linklist_test.get(i) << endl;
    }

}
