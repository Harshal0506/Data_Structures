#include <iostream>

using namespace std;
struct Toeplitz{
    int *A;
    int n;



};

void Set(struct Toeplitz *m,int i,int j,int k){
if(i==1 || j==1){
    if(j>=i)
    m->A[j-i]=k;
    else
        m->A[m->n-2+i]=k;

}

}
int Get(struct Toeplitz m,int i,int j){
if(j>=i)
    return m.A[j-i];
return m.A[m.n-1+i-j];
}
void Display(struct Toeplitz m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        cout<<Get(m,i,j)<<' ';

    }
    cout<<endl;
}

}


int main()
{
struct Toeplitz m;
 int i,j,x;

 printf("Enter Dimension");
 scanf("%d",&m.n);
 m.A=(int *)malloc((2*m.n-1)*sizeof(int));
 printf("enter all elements");
 for(i=1;i<=m.n;i++)
 {
 for(j=1;j<=m.n;j++)
 {
 scanf("%d",&x);
 Set(&m,i,j,x);
 }
 }
 printf("\n\n");
 Display(m);
x=m.n;       //way it is stored in A
x=2*x-1;
 for(int i=0;i<x;i++)
    cout<<m.A[i]<<' ';





    return 0;
}
