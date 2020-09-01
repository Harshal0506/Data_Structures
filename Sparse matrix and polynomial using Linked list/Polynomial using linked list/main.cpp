#include <iostream>
#include<cmath>

using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node* Next;


}*Poly=NULL;

void Create(){
struct Node *Last,*t;
int num;
cout<<"Enter the number of elements!!!"<<endl;
cin>>num;
cout<<"Enter the coefficient and exponent one by one"<<endl;
for(int i=1;i<=num;i++){
    if(i==1){
        Poly=new Node;
        Last=Poly;
        Last->Next=NULL;
        cin>>Last->coeff>>Last->exp;
    }else{
    t=new Node;

    cin>>t->coeff>>t->exp;
    t->Next=NULL;
    Last->Next=t;
    Last=t;

    }

}




}

void Display(struct Node *P){
    while(P){
        printf("%dx%d+",P->coeff,P->exp);
        P=P->Next;
    }
    printf("\b \n");



}

long Evaluate(struct Node *P,int x){
    long val=0;
    while(P){
        val+=P->coeff*pow(x,P->exp);
        P=P->Next;
    }
    return val;







}
int main()
{
    Create();
    Display(Poly);

    cout<<Evaluate(Poly,1)<<endl;
    return 0;
}
