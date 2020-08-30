#include <iostream>

using namespace std;

struct Node {
int Data;
struct Node *Next;


}*Head=NULL;

void Create(int A[],int n){
struct Node *Last;
Head=new Node;
Last=Head;
Head->Data=A[0];
Head->Next=Head;
for(int i=1;i<n;i++){
    struct Node *t=new Node;
    t->Data=A[i];
    t->Next=Last->Next;
    Last->Next=t;
    Last=t;


}




}

void Display(struct Node*P){
    if(P==NULL)
        return ;
    do{
        cout<<P->Data<<' ';
        P=P->Next;


    }while(P!=Head);






}

void RDisplay(struct Node *P){
    static int Flag=0;
if (P==NULL)
    return;

 if(P!=Head || Flag==0){
    Flag=1;
    cout<<P->Data<<' ';
    RDisplay(P->Next);


 }
 else{
    Flag=0;
 }




}

int Length(struct Node *P)
{
 int Len=0;
 if(P==NULL)
    return Len;
 do
 {
 Len++;
 P=P->Next;

 }while(P!=Head);
 return Len;
}

void Insert(struct Node*P,int index,int x){
if(index<0 || index >Length(P))
    return ;
struct Node *t=new Node;
t->Data=x;
if(index==0){
    if(P==NULL)
    {
        t->Next=t;
        Head=t;

    }else{
    while(P->Next!=Head){
        P=P->Next;
    }
    t->Next=Head;
    P->Next=t;
    Head=t;


    }





}else{
for(int i=1;i<=index-1;i++)
    P=P->Next;

t->Next=P->Next;
P->Next=t;






}
}





int Delete(struct Node *P,int index){
if(index<=0 || index>Length(P))
    return -1;
int x;
struct Node*Q;
if(index==1){
    while(P->Next!=Head)P=P->Next;
    x=Head->Data;
    if(Head==P){
        delete P;
        Head=NULL;

    }else{

    P->Next=Head->Next;
    delete Head;
    Head=P->Next;


    }
    }else{
    for(int i=1;i<index-1;i++){
        P=P->Next;
    }
    Q=P->Next;
    x=Q->Data;
    P->Next=Q->Next;
    delete Q;






    }


    return x;
}













int main()
{
    /*int A[]={1,2,3,100};
    Create(A,4);
    RDisplay(Head);*/

    int A[]={1};
    Create(A,1);
    RDisplay(Head);
    cout<<Delete(Head,1)<<endl;
    RDisplay(Head);

    cout<<endl;
    return 0;
}
