//speciality of symmetric matrix is that M[i,j]=M[j,i]
//so we need to store either upper or lower Triangular matrix either in row or column major
//we are choosing row major of lower Triangular matrix
#include <iostream>

using namespace std;

struct Symmetric{
    int *A;
    int n;



};
/*Row Major*/
void Set(struct Symmetric *m,int i,int j,int k){
if(i>=j){
    m->A[i*(i-1)/2+j-1]=k;

}

}
int Get(struct Symmetric m,int i,int j){
if(i>=j)
    return m.A[i*(i-1)/2+j-1];

return Get(m,j,i);
}
void Display(struct Symmetric m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        cout<<Get(m,i,j)<<' ';

    }
    cout<<endl;
}

}
int main()
{
struct Symmetric m;
 int i,j,x;

 printf("Enter Dimension");
 scanf("%d",&m.n);
 m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
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
}
