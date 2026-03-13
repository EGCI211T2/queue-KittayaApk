#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class NODE{
public:
    int order;
    int qty;
    NODE* next;

    NODE(int o,int q){
        order=o;
        qty=q;
        next=NULL;
    }
};

typedef NODE* NodePtr;

#endif