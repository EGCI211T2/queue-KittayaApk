#include <iostream>
#include <cstring>
#include "Queue.h"

using namespace std;

string foodName(int order){

    if(order==1) return "Green curry";
    if(order==2) return "Somtum";
    if(order==3) return "Chicken basil";

    return "No Food";
}

int foodPrice(int order){

    if(order==1) return 100;
    if(order==2) return 90;
    if(order==3) return 200;

    return 0;
}

int main(int argc,char** argv){

    Queue q;

    for(int i=1;i<argc;i++){

        if(strcmp(argv[i],"x")==0){

            NodePtr cust=q.dequeue();

            if(cust==NULL){
                cout<<"Queue is empty"<<endl;
                continue;
            }

            string food=foodName(cust->order);
            int price=foodPrice(cust->order)*cust->qty;

            cout<<food<<endl;
            cout<<"Removing "<<food<<endl;

            if(food=="No Food"){
                cout<<"We don't have that food. You don't have to pay."<<endl;
                cout<<"=============="<<endl;
                delete cust;
                continue;
            }

            cout<<"You have to pay "<<price<<endl;

            int cash=0;

            while(cash<price){
                int c;
                cout<<"Cash:";
                cin>>c;
                cash+=c;
            }

            cout<<"Thank you"<<endl;

            if(cash>price){
                cout<<"Here is your "<<cash-price<<" change."<<endl;
            }

            cout<<"=============="<<endl;

            delete cust;
        }

        else{

            int order=atoi(argv[i]);
            int qty=atoi(argv[++i]);

            q.enqueue(order,qty);
        }
    }

    if(!q.isEmpty()){

        int count=0;
        NodePtr temp=q.dequeue();

        while(temp!=NULL){
            count++;
            NodePtr next=q.dequeue();
            q.enqueue(temp->order,temp->qty);
            delete temp;
            temp=next;
        }

        cout<<"The shop is closed. There are "<<count<<" left."<<endl;

        NodePtr cust=q.dequeue();

        if(cust){
            string food=foodName(cust->order);
            cout<<food<<endl;
            cout<<"Removing "<<food<<endl;
            delete cust;
        }
    }
}