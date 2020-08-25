#include <iostream>

using namespace std;

struct UpperTriangular{
    int *A;
    int n;



};


/*Row Major*/
void Set(struct UpperTriangular *m,int i,int j,int k){
if(j>=i){
    m->A[m->n*(i-1)-(i-1)*(i-2)/2+j-i]=k;

}

}
int Get(struct UpperTriangular m,int i,int j){
if(j>=i)
    return m.A[m.n*(i-1)-(i-1)*(i-2)/2+j-i];
return 0;
}
void Display(struct UpperTriangular m){
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        if (j>=i)
            cout<<m.A[m.n*(i-1)-(i-1)*(i-2)/2+j-i]<<' ';
        else
            cout<<0<<' ';

    }
    cout<<endl;
}

}


/*Column major*/
/*

void Set(struct UpperTriangular *m,int i,int j,int k){
if(j>=i){
    m->A[j*(j-1)/2+i-1]=k;

}

}
int Get(struct UpperTriangular m,int i,int j){
if(j>=i)
    return m.A[j*(j-1)/2+i-1];
return 0;
}
void Display(struct UpperTriangular m){
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
struct UpperTriangular m;
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

