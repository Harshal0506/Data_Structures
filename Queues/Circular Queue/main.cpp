#include <iostream>

using namespace std;

struct Queue{
int Size;
int Front;
int Rear;
int *Q;



};


void create(struct Queue *q,int s){
    q->Size=s;
    q->Front=q->Rear=0;
    q->Q=new int [q->Size];


}

void enqueue(struct Queue *q,int x){
if((q->Rear+1)%q->Size==q->Front)
        cout<<"Queue is Full"<<endl;
else{
    q->Rear=(q->Rear+1)%q->Size;
    q->Q[q->Rear]=x;
}



}

int dequeue(struct Queue *q){
int x=-1;
if(q->Front==q->Rear)
    cout<<"Queue is Empty"<<endl;
else{
    q->Front=(q->Front+1)%q->Size;
    x=q->Q[q->Front];
}
return x;



}

void display(struct Queue q){
if(q.Front==q.Rear)
    return;
int i=q.Front;
do{
        i=(i+1)%q.Size;
        cout<<q.Q[i]<<' ';





}while(i!=q.Rear);
cout<<endl;





}


int main()
{
    struct Queue q;
 create(&q,5);

 enqueue(&q,10);
 enqueue(&q,20);
 enqueue(&q,30);
enqueue(&q,30);

 display(q);

 printf("%d\n",dequeue(&q));

 display(q);
 return 0;
}
