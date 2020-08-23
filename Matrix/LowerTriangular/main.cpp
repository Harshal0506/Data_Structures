#include <iostream>

using namespace std;

struct LowerTriangular{
    int *A;
    int n;



};
/*Row Major*/
void Set(struct LowerTriangular *m,int i,int j,int k){
if(i>=j){
    m->A[i*(i-1)/2+j-1]=k;

}

}
int Get(struct LowerTriangular m,int i,int j){
if(i>=j)
    return m.A[i*(i-1)/2+j-1];
return 0;
}
void Display(struct LowerTriangular m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        if (i>=j)
            cout<<m.A[i*(i-1)/2+j-1]<<' ';
        else
            cout<<0<<' ';

    }
    cout<<endl;
}

}

/*Column major*/


/*void Set(struct LowerTriangular *m,int i,int j,int k){
if(i>=j){
    m->A[m->n*(j-1)-(j-1)*(j-2)/2+i-j]=k;

}

}
int Get(struct LowerTriangular m,int i,int j){
if(i>=j)
    return m.A[m.n*(j-1)-(j-1)*(j-2)/2+i-j];
return 0;
}
void Display(struct LowerTriangular m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){

            cout<<Get(m,i,j)<<' ';


    }
    cout<<endl;
}

}
*/



int main()
{
struct LowerTriangular m;
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
/* x=m.n;       //column or row major
x=x*(x+1)/2;
 for(int i=0;i<x;i++)
    cout<<m.A[i]<<' ';
*/




    return 0;
}
