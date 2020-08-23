#include <iostream>

using namespace std;

struct Diagonal{
 int A[10];
 int n;


};
void Set(struct Diagonal* D,int i,int j,int k){
 if (i==j){
    D->A[i-1]=k;
 }

}
int Get (struct Diagonal D ,int i,int j){
 if (i==j){
    return D.A[i-1];
 }
 return 0;


}
 void Display(struct Diagonal D){
    for (int i=1;i<=D.n;i++){
        for(int j=1;j<=D.n;j++){
            cout<<Get(D,i,j)<<' ';
        }
        cout<<endl;
    }


 }

int main()
{
    struct Diagonal m;
    m.n=4;

    Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,4,4,12);
    printf("%d \n",Get(m,2,2));
    Display(m);


    return 0;
}
