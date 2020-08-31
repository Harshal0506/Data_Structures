#include <iostream>

using namespace std;
struct Node{
 struct Node* Prev;
 int Data;
 struct Node * Next;

}*Head=NULL;

void Create(int A[],int n){
    struct Node*Last=NULL;
    Head=new Node;

    Head->Data=A[0];
    Head->Prev=NULL;
    Head->Next=NULL;
    Last=Head;
    for(int i=1;i<n;i++){
        struct Node *t=new Node;
        t->Data=A[i];
        t->Next=Last->Next;
        t->Prev=Last;
        Last->Next=t;
        Last=Last->Next;


    }
    }

void Display(struct Node *P){

while(P){
    cout<<P->Data<<' ';
    P=P->Next;
}
cout<<endl;
}



int  Length(struct Node *P){
int len=0;
while(P){
    len++;
    P=P->Next;


}
return len;
}

void Insert(struct Node *P,int index,int x){
if(index<0 || index>Length(P))
    return ;
struct Node *t=new Node;
t->Data=x;
if(index==0){
    t->Prev=NULL;
    t->Next=Head;
    if (Head)
        Head->Prev=t;
    Head=t;
}else{
for(int i=1;i<=index-1;i++)
    P=P->Next;
t->Prev=P;
t->Next=P->Next;
if(P->Next)
    P->Next->Prev=t;
P->Next=t;

}
}

int  Delete(struct Node* P,int index){
if(index<1 || index>Length(P))
    return -1;
int x;
if(index==1){
        x=P->Data;
        P=P->Next;
        if(P)
            P->Prev=NULL;
        delete Head;
        Head=P;



}else{
for(int i=1;i<=index-1;i++)
        P=P->Next;
    x=P->Data;
    P->Prev->Next=P->Next;
    if(P->Next)
        P->Next->Prev=P->Prev;
    delete P;

}
return x;
}

void Reverse(struct Node *P){
if(P==NULL)
    return ;
struct Node *temp;
while(P){

    temp=P->Prev;
    P->Prev=P->Next;
    P->Next=temp;
    if(P->Prev==NULL){
        Head=P;
    }
    P=P->Prev;




}





}
int main()
{   int A[]={1};
    Create(A,1);
    Display(Head);
    Reverse(Head);
    Display(Head);

    return 0;
}
