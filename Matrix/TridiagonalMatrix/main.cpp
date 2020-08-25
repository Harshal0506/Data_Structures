#include <iostream>

using namespace std;

struct Tridiagonal{
    int *A;
    int n;



};
/*Row Major*/
void Set(struct Tridiagonal *m,int i,int j,int k){
if(abs(i-j)<=1){
    if (i-j==1)
        m->A[j-1]=k;
    else if(i==j)
        m->A[m->n-2+i]=k;
    else
            m->A[2*m->n-2+i]=k;

}

}
int Get(struct Tridiagonal m,int i,int j){
if(abs(i-j)<=1){

    if (i-j==1)
        return m.A[j-1];
    else if(i==j)
        return m.A[m.n-2+i];
    else
            return m.A[2*m.n-2+i];
}
return 0;
}
void Display(struct Tridiagonal m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++)
        cout<<Get(m,i,j)<<' ';
    cout<<endl;
}

}


int main()
{
struct Tridiagonal m;
 int i,j,x;

 printf("Enter Dimension");
 scanf("%d",&m.n);
 m.A=(int *)malloc((3*m.n-2)*sizeof(int));
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

/*x=m.n;       //way the matrix is stored in A
x=3*x-2;
 for(int i=0;i<x;i++)
    cout<<m.A[i]<<' ';
    */


    return 0;
}
