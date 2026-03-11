#ifndef queue_h
#define queue_h
#include <iostream>
#include "Node.h"
using namespace std;

class Queue {
	NodePtr headPtr, tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

void Queue::enqueue(int x){
  NodePtr new_node = new NODE(x);

  if(new_node){ 
    /* Add head and tail for me please */

   //1. connect & Change tail
   if(size > 0){
       tailPtr->set_next(new_node);
   }
   else{
    // 2. (may be) change head  when the queue is empty
     headPtr = new_node;
   }

   tailPtr = new_node;

   // 3. increase size
   size++;
  }
}

int Queue::dequeue(){

  if(size == 0){
      cout << "Empty Queue" << endl << endl;
      return -1;
  }

  /* Add head and tail for me please */

  NodePtr t = headPtr;
  int value = headPtr->get_value();

  headPtr = headPtr->get_next();

  if(headPtr == nullptr){
     tailPtr = nullptr;
  }

  --size;
  delete t;

  cout << "dequeing " << value << endl << endl;
  return value;
}

Queue::Queue(){
    //initialize Queue
    size = 0;
    headPtr = nullptr;
    tailPtr = nullptr;
}

Queue::~Queue(){
      
    cout << "Clearing queue" << endl << endl;

    //delete all remaning Queue (i.e. DQ all) 
    while(size > 0){
        dequeue();
    }
}

#endif