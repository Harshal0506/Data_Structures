#include <iostream>

using namespace std;

class LowerTriangular{
private:

    int *A;
    int n;
public:
    LowerTriangular(){
    n=2;
    A=new int [3];


    }
    LowerTriangular(int n){
    this->n=n;
    A=new int [n*(n+1)/2];

    }
    ~LowerTriangular(){
    delete []A;
    A=NULL;
    }
    /*Row Major*/
    void SetRowMajor(int i,int j,int k){
    if(i>=j){
        A[i*(i-1)/2+j-1]=k;

    }

    }
    int GetRowMajor(int i,int j){
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    return 0;
    }
    void DisplayRowMajor(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            cout<<GetRowMajor(i,j)<<' ';


    }
    cout<<endl;
}


}

/*column Major*/
void SetColumnMajor(int i,int j,int k){
if(i>=j){
    A[n*(j-1)-(j-1)*(j-2)/2+i-j]=k;

}

}
int GetColumnMajor(int i,int j){
if(i>=j)
    return A[n*(j-1)-(j-1)*(j-2)/2+i-j];
return 0;
}
void DisplayColumnMajor(){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){

            cout<<GetColumnMajor(i,j)<<' ';


    }
    cout<<endl;
}

}








};



int main()
{

 int i,j,x,dim;

 printf("Enter Dimension");
 scanf("%d",&dim);
 LowerTriangular m(dim);

 printf("enter all elements");
 for(i=1;i<=dim;i++)
 {
 for(j=1;j<=dim;j++)
 {
 scanf("%d",&x);
 m.SetColumnMajor(i,j,x);
 }
 }
 printf("\n\n");
 m.DisplayColumnMajor();
/* x=m.n;       //column or row major
x=x*(x+1)/2;
 for(int i=0;i<x;i++)
    cout<<m.A[i]<<' ';
*/




    return 0;
}
