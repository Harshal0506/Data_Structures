#include <iostream>
using namespace std;
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
    cout<<endl;
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

/*  normal Linear search
struct Node * Search(struct Node *P,int Key){

while(P){
    if(Key==P->Data){

        return P;
    }

    P=P->Next;
}
return NULL;


}
*/
//improved Search
struct Node * Search(struct Node *P,int Key){
struct Node *q=NULL;
while(P){
    if(Key==P->Data){
        q->Next=P->Next;
        P->Next=Head;
        Head=P;
        return P;
    }
    q=P;
    P=P->Next;
}
return NULL;


}


struct Node* RSearch(struct Node *P,int Key){
if(P==NULL)
    return NULL;
if(P->Data==Key)
    return P;
return RSearch(P->Next,Key);


};


void Insert(struct Node *P,int index,int x){
    if(index<0 || index>Count(P))
        return ;
    else{
        struct Node *t;
        t=new Node;
        t->Data=x;
        if(index==0){
            t->Next=Head;
            Head=t;
        }else{
        for(int i=1;i<=index-1;i++)
            P=P->Next;

        t->Next=P->Next;
        P->Next=t;

        }
    }
}

/*Assuming whole list is created by insertlast
void InsertLast(int x){
struct Node *t=new Node;
static Node* Last=NULL;

t->Data=x;
t->Next=NULL;
if(Head==NULL)

    Head=Last=t;
else{
    Last->Next=t;
    Last=Last->Next;
}





}

*/

void InsertSorted(struct Node *P,int x){
    struct Node *t=new Node;
    struct Node *Q=NULL;
    t->Data=x;

        while(P && P->Data<x){
            Q=P;
            P=P->Next;
        }
        if (P==Head){
            t->Next=Head;
            Head=t;
        }else{
        t->Next=Q->Next;
        Q->Next=t;


        }









}


int Delete(struct Node*P,int index){
    int x;
    struct Node *Q;
    if (index<1 || index>Count(P))
        return -1;
    if(index==1){
        Head=Head->Next;
        x=P->Data;
        delete P;
        return x;
    }else{
    for(int i=1;i<=index-1;i++){
        Q=P;
        P=P->Next;

    }
    Q->Next=P->Next;
    x=P->Data;
    delete P;
    return x;



    }
}

bool IsSorted(struct Node *P){
    int x=INT_MIN;
    while(P){
        if(P->Data<x)
            return false;
        x=P->Data;
        P=P->Next;


    }
    return true;
    }
//only in sorted LL
void RemoveDublicate(struct Node *P){
if(P==NULL)
    return;
struct Node* Q=P->Next;
while(Q){
    if(P->Data ==Q->Data){
        P->Next=Q->Next;
        free(Q);
        Q=P->Next;
    }
    else{
        P=Q;
        Q=Q->Next;
    }
}

}
//changing the data
void Reverse1(struct Node *P)
{
    int *A,i=0;
    A=new int[Count(P)];
    struct Node*Q=P;//As we need P for future reference
    while(Q!=NULL){
        A[i++]=Q->Data;
        Q=Q->Next;
    }
    i-=1;
    Q=P;
    while(Q!=NULL){
        Q->Data=A[i--];
        Q=Q->Next;
    }
}

//Reversing the link
void Reverse2(struct Node *P){
struct Node*Q,*R;
Q=R=NULL;
while(P){
    R=Q;
    Q=P;
    P=P->Next;
    Q->Next=R;



}
Head=Q;
}


void Reverse3(struct Node*Q,struct Node *P){
    if(P==NULL)
        Head=Q;
    else{
        Reverse3(P,P->Next);
        P->Next=Q;
    }
}
int main(){
int A[]={1,2,3,4,5,6,7,8,9,10};
 Create(A,10);
 Display(Head);
 Reverse3(NULL,Head);
Display(Head);






    return 0;
}


