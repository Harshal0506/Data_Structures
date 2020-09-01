#include <iostream>



using namespace std;


struct  Node{
int Col;
int Data;
struct Node *Next;


};

void Create(struct Node *A[],int m){
int num;
struct Node *Last,*t;
for(int i=0;i<m;i++){
    cout<<"enter the number of element in row "<<i+1<<endl;
    cin>>num;
    cout<<"enter elements one by one if any in column and data format"<<endl;
    for(int j=1;j<=num;j++){
         t=new Node;
        cin>>t->Col>>t->Data;
        t->Next=NULL;

        if(j==1){
           Last=A[i]=t;

        }else{
        Last->Next=t;
        Last=t;


        }

    }
}


}

void Display(struct Node *A[],int m,int n){
struct Node *p;
for(int i=0;i<m;i++){
     p=A[i];
    for(int j=1;j<=n;j++){
    if(p&&p->Col==j){
        cout<<p->Data<<' ';
        p=p->Next;
    }else
    cout<<"0 ";
    }
    cout<<endl;
}



}
int main()
{   int m,n;
    cout<<"enter row and column of the matrix"<<endl;
    cin>>m>>n;
    struct Node *A[m]={0};
    Create(A,m);
    Display(A,m,n);

    return 0;
}
