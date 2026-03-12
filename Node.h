#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class NODE{
public:
    int order;
    int qty;
    NODE* next;

    NODE(int o,int q){
        order = o;
        qty = q;
        next = NULL;
    }

    void set_next(NODE* t){
        next = t;
    }

    NODE* get_next(){
        return next;
    }
};

typedef NODE* NodePtr;

#endif