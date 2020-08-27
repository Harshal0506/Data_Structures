#include <iostream>

#include<bits/stdc++.h>

//global
struct Node{
int Data;
struct Node* Next;

}*Head;

void Create(int A[],int n){
    int i;
    struct Node *t,*Last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->Data=A[0];
    Head->Next=NULL;
    Last=Head;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->Data=A[i];
        t->Next=NULL;
        Last->Next=t;
        Last=Last->Next;

    }
}
//display in LL
//yes it can access it directly ese hi pass kiya h as we dont want to change Head
void Display(struct Node *P)
{
    while(P){
        printf("%d ",P->Data);
        P=P->Next;
    }
}

void RDisplay(struct Node *P){
    if(P){
        printf("%d ",P->Data);
        RDisplay(P->Next);
    }


}
void RBackDisplay(struct Node *P){
if(P){
    RBackDisplay(P->Next);
    printf("%d ",P->Data);
}



}

//Count and Sum
int Count(struct Node *P){
int Sum=0;
while(P){
    Sum++;
    P=P->Next;
}
return Sum;

}

int RCount(struct Node *P){
if(P==NULL){
    return 0;
}else{
    return RCount(P->Next)+1;

}
}

int Sum(struct Node *P){
int S=0;
while(P){
    S+=P->Data;
    P=P->Next;
}
return S;



}

int RSum(struct Node *P ){
    if(P==NULL){
        return 0;

    }else{
        return RSum(P->Next)+P->Data;

    }


}

//max in a LL

int Max(struct Node *P){
int m=P->Data;
while(P){
    if (P->Data>m)
        m=P->Data;
    P=P->Next;
}
return m;

}


int RMax(struct Node *P){
if(P==0)
    return INT_MIN;
int x=RMax(P->Next);
return x>P->Data? x:P->Data;


}
int main()
{
    int A[]={3,5,7,109,25,8,32,2};
    Create(A,8);
    printf("%d %d ",Max(Head),RMax(Head));

    printf("\n");

    return 0;
}


