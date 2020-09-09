#include <iostream>

using namespace std;
struct Queue
{
    int Size;
    int Front;
    int Rear;
    int *Q;
};

void create(struct Queue*q,int s){
    q->Size=s;
    q->Q=new int [q->Size];
    q->Front=q->Rear=-1;


}

void enqueue(struct Queue *q,int x){
if(q->Rear==q->Size-1)
    cout<<"Queue Overflow";
else{
    q->Rear++;
    q->Q[q->Rear]=x;
}


}
int dequeue(struct Queue *q){
    int x=-1;
if(q->Rear==q->Front)
    cout<<"Queue Underflow";
else{
    q->Front++;
    x=q->Front;
}

return x;

}


void display(struct Queue q ){
for(int i=q.Front+1;i<=q.Rear;i++)
    cout<<q.Q[i]<< ' ';
cout<<endl;




}
int main()
{

    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);

    dequeue(&q);
    dequeue(&q);
    display(q);





    return 0;
}
