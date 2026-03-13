#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue{
    NodePtr headPtr;
    NodePtr tailPtr;

public:
    Queue(){
        headPtr=NULL;
        tailPtr=NULL;
    }

    void enqueue(int order,int qty);
    NodePtr dequeue();
    bool isEmpty();
};

void Queue::enqueue(int order,int qty){

    NodePtr new_node = new NODE(order,qty);

    if(headPtr==NULL){
        headPtr=new_node;
        tailPtr=new_node;
    }
    else{
        tailPtr->next=new_node;
        tailPtr=new_node;
    }
}

NodePtr Queue::dequeue(){

    if(headPtr==NULL)
        return NULL;

    NodePtr temp=headPtr;
    headPtr=headPtr->next;

    if(headPtr==NULL)
        tailPtr=NULL;

    return temp;
}

bool Queue::isEmpty(){
    return headPtr==NULL;
}

#endif