#ifndef QUEUES_H_INCLUDED
#define QUEUES_H_INCLUDED

#include <iostream>

using namespace std;

struct Node{
 Node * lchild;
 Node * rchild;
 int data;


};

struct Queue{
int Size;
int Front;
int Rear;
Node **Q;



};


void create(struct Queue *q,int s){
    q->Size=s;
    q->Front=q->Rear=0;
    q->Q=new Node * [q->Size];


}

void enqueue(struct Queue *q,Node * x){
if((q->Rear+1)%q->Size==q->Front)
        cout<<"Queue is Full"<<endl;
else{
    q->Rear=(q->Rear+1)%q->Size;
    q->Q[q->Rear]=x;
}



}

Node * dequeue(struct Queue *q){
Node * x=NULL;
if(q->Front==q->Rear)
    cout<<"Queue is Empty"<<endl;
else{
    q->Front=(q->Front+1)%q->Size;
    x=q->Q[q->Front];
}
return x;



}

bool IsEmpty(struct Queue q){
    return q.Front==q.Rear;

}



#endif // QUEUES_H_INCLUDED
