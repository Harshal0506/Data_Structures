#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
struct Node{
int Data;
struct Node* Next;

}*Head1,*Head2;


void Create1(int A[],int n){
    int i;
    struct Node *t,*Last;
    Head1=(struct Node *)malloc(sizeof(struct Node));
    Head1->Data=A[0];
    Head1->Next=NULL;
    Last=Head1;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->Data=A[i];
        t->Next=NULL;
        Last->Next=t;
        Last=Last->Next;

    }
}

void Create2(int A[],int n,struct Node *P){
    int i;
    struct Node *t,*Last;
    Head2=(struct Node *)malloc(sizeof(struct Node));
    Head2->Data=A[0];
    Head2->Next=NULL;
    Last=Head2;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->Data=A[i];
        t->Next=NULL;
        Last->Next=t;
        Last=Last->Next;

    }
    Last->Next=P;
}

void Display(struct Node *P)
{
    while(P){
        printf("%d ",P->Data);
        P=P->Next;
    }
    cout<<endl;
}
void Intersection(struct Node*P,struct Node *Q){
stack<Node*>s1;
stack<Node*>s2;

while(P){
    s1.push(P);
    P=P->Next;
}
while(Q){
    s2.push(Q);
    Q=Q->Next;
}
struct Node *result=NULL;
while(s1.top()==s2.top()){
        result=s1.top();
        s1.pop();
        s2.pop();

}
cout<<"Intersection node is"<<result->Data<<endl;








}



int main()
{
    int A[]={9,2,3,4,5};
    Create1(A,5);
    int B[]={9,8,7,6,2};
    Create2(B,5,Head1->Next);
    Display(Head1);
    Display(Head2);
    Intersection(Head1,Head2);

    return 0;
}
