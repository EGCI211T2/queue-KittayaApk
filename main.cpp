#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Queue.h"

int main(int argc , char **argv) {

    Queue q;
    int cust_no = 0;

    for(int i=1;i<argc;i++){

        if(strcmp(argv[i],"x")==0){

            NodePtr cust = q.dequeue();

            if(cust==NULL){
                cout<<"Queue is empty"<<endl;
            }

            else{

                cust_no++;

                cout<<"Customer no: "<<cust_no<<endl;

                int price=0;

                if(cust->order==1){
                    cout<<"Green curry"<<endl;
                    price = 200 * cust->qty;
                }

                else if(cust->order==2){
                    cout<<"Thai basil"<<endl;
                    price = 100 * cust->qty;
                }

                cout<<"You have to pay "<<price<<endl;

                int cash;

                cout<<"Cash:";
                cin>>cash;

                while(cash < price){
                    cout<<"Cash:";
                    cin>>cash;
                }

                cout<<"Thank you"<<endl;

                if(cash > price){
                    cout<<"Change is:"<<cash-price<<endl;
                }

                delete cust;
            }

        }

        else{

            int order = atoi(argv[i]);
            int qty = atoi(argv[i+1]);

            cout<<"My order is "<<order<<endl;

            q.enqueue(order,qty);

            i++;
        }
    }

    cout<<"==================================="<<endl;
    cout<<"There are "<<q.get_size()<<" ppl left in the queue"<<endl;

    return 0;
}