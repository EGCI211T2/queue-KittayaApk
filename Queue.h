#ifndef queue_h
#define queue_h

#include <iostream>
#include "Node.h"
using namespace std;

class Queue {
	NodePtr headPtr, tailPtr;
	int size;

public:
    void enqueue(int,int);
    NodePtr dequeue();
    int get_size();
    Queue();
};

Queue::Queue(){
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
}

void Queue::enqueue(int order,int qty){

    NodePtr new_node = new NODE(order,qty);

    if(size==0){
        headPtr = tailPtr = new_node;
    }
    else{
        tailPtr->set_next(new_node);
        tailPtr = new_node;
    }

    size++;
}

NodePtr Queue::dequeue(){

    if(size==0)
        return NULL;

    NodePtr temp = headPtr;

    headPtr = headPtr->get_next();

    if(headPtr==NULL)
        tailPtr=NULL;

    size--;

    return temp;
}

int Queue::get_size(){
    return size;
}

#endif