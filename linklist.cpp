#include"Str.h"
#include<iostream>
using namespace std;

#include"Str.h"
using namespace std;
#include<iostream>
using namespace std;


class linklist
{
private:

    struct link
    {
        int var;
        link* next;
    };
    link* cell;
public:
    linklist() : cell(NULL) { }
    void pop_back(int elem) {
        link* buflink = new link;
        (*buflink).var = elem;
        buflink->next = cell;
        cell = buflink;
    }
    void push_back(int elem) {
        static bool first= true;
        if (first) {
            link* buflink = new link;
            buflink->var = elem;
            buflink->next = cell;
            cell = buflink;
        }
        else {
        link* current = cell;
        while (current) {
            if (!current->next) {
                link* buflink = new link;
                buflink->var = elem;
                buflink->next = current->next;
                current->next = buflink;
                break;
            }
            current = current->next;
        }
          }
          if (elem || !elem)first = false;
    }
    void display() const {
        link* current=cell;
        while (current)
        {
            cout << current->var << endl;
            current = current->next;
        }
    }
    ~linklist() {
        for (link* current; cell; )
        {
            current = cell;
            cell = cell->next;
            delete current;
        }
        delete cell;
    }
};

int main() {
    linklist l1;
    l1.pop_back(11);
    l1.pop_back(21);
    l1.pop_back(31);
    l1.display();
    cout << endl << endl;
   linklist l2;
    l2.push_back(11);
    l2.push_back(21);
    l2.push_back(31);
    l2.display();
}
//
//
//void push_back(int elem) {
//    //static bool first= true;
//    //if (first) {
//    //    link* buflink = new link;
//    //    buflink->var = elem;
//    //    link* buflink1 = new link;
//    //    buflink->next = buflink1;
//    //    buflink1->next = cell;
//    //    cell = buflink;
//    //}
//    //else {
//    link* current = cell;
//    unsigned short pr = 0;
//    while (current) {
//        if (!current->next && pr == 0) {
//            current->var = elem;
//            link* buflink = new link;
//            buflink->next = current->next;
//            current->next = buflink;
//            ++pr;
//        }
//        current = current->next;
//    }
//    /*  }
//      if (elem || !elem)first = false;*/
//
//}