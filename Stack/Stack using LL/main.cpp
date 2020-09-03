#include <iostream>

using namespace std;

struct Node{
int data;
struct Node *next;



}*top=NULL;
//not preffered method it should be used when we know only one stack will be created
//everytime we should take it as a parameter to function

void Push(int x){
    struct Node *t=new Node;
    if (t==NULL){
        cout<<"stack overflow"<<endl;
        return;
    }
    t->data=x;
    t->next=top;
    top=t;



}

int Pop(){
    int x=-1;


    if(top==NULL)
        cout<<"Stack underflow"<<endl;

    else{
        struct Node *p=top;
        top=top->next;
        x=p->data;
        delete p;


    }
    return x;



}

void Display(){
struct Node *p=top;
while(p){
    cout<<p->data<<' ';
    p=p->next;
}
cout<<endl;




}

int Peek(int pos){
struct Node *p=top;

for(int i=0;p && i<pos-1;i++)
    p=p->next;
if(p)
    return p->data;
return -1;




}

int  isEmpty(){
    return top?0:1;
}
int isFull(){
    struct Node *t=new Node;
    int r=t?0:1;
    delete t;
    return r;
}

int StackTop(){
    if(isEmpty())
        return -1;
    return top->data;



}


int main()
{

    int A[] = {1, 3, 5, 7, 9};



    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        Push(A[i]);
    }

    cout << "Stack peek at 3rd: " << Peek(3) << endl;
    cout << "Stack peek at 10th: " << Peek(10) << endl;
    cout << "Stack top: " << StackTop() << endl;
    cout << "Stack full: " << isFull() << endl;
    cout << "Stack empty: " << isEmpty() << endl;

    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << Pop() << ", " << flush;
    }
    cout << endl;

    // Underflow
    cout << Pop()<<isEmpty() << endl;

    return 0;



 return 0;
}
