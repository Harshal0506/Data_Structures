#include <iostream>

using namespace std;
struct Node {
int data;
struct Node *next;

}*Front=NULL,*Rear=NULL;

void enqueue(int x){
    struct Node *t=new Node;
    if (t==NULL)
        cout<<"Queue is Full\n";
    else{
        t->data=x;
        t->next=NULL;
        if(Front==NULL){
            Front = Rear=t;

        }else{

        Rear->next=t;
        Rear=t;

    }
}
}

int  dequeue(){
    int x=-1;
if(Front==NULL )
    cout<<"Queue is Empty"<<endl;
else{
    struct Node *p=Front;
    Front=Front->next;
    x=p->data;
    delete p;


}
return x;






}

void Display(){
struct Node *p=Front;
while(p){

    cout<<p->data<<' ';
    p=p->next;
}
cout<<endl;


}

int main()
{
    enqueue(10);
 enqueue(20);
 enqueue(30);
 enqueue(40);
 enqueue(50);

 Display();

 printf("%d ",dequeue());


}
