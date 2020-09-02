#include <iostream>

using namespace std;


struct Stack{
int Size;
int Top;
int *S;

};


void Create(Stack *St){
cout<<"Enter the size of array you want"<<endl;
cin>>St->Size;
St->Top=-1;
St->S=new int [St->Size];
}

void Display(struct Stack St){
for(int i=St.Top;i>=0;i--)
    cout<<St.S[i]<<' ';
    cout<<endl;
}

void Push(struct Stack *St,int x){
if (St->Top==St->Size-1)
{
    cout<<"Stack overflow"<<endl;

}else{
St->Top++;
St->S[St->Top]=x;



}
}
int  Pop(struct Stack *St){
int x=-1;
if(St->Top==-1)
    cout<<"Stack underflow"<<endl;

else
 x=St->S[St->Top--];

return x;
}

int Peek(struct Stack St,int pos){
    int x=-1;
    if(St.Top-pos+1<0)
        cout<<"Invalid Position"<<endl;
    else
        x=St.S[St.Top-pos+1];
    return x;
}

int isEmpty(struct Stack St){
    if(St.Top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack St){

    return St.Top==St.Size-1;

}

int StackTop(struct Stack St){
    if(!isEmpty(St))
        return St.S[St.Top];
    return -1;

}



int main()
{

    struct Stack St;
    Create(&St);
    cout<<isEmpty(St)<<endl;
    Push(&St,10);
    Push(&St,20);
    Push(&St,30);
    Push(&St,40);
    cout<<isFull(St)<<endl;
    printf("%d \n",Peek(St,2));
    Display(St);
    cout<<Pop(&St)<<endl;

    Display(St);


    return 0;
}
