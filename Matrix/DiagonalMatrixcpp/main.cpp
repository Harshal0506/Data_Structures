#include <iostream>

using namespace std;

class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(){
    n=2;
    A=new int[2];

    }
    Diagonal(int n){
    this->n=n;
    A=new int [n];

    }
    ~Diagonal(){

    delete []A;
    A=NULL;
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();



};
void Diagonal::Set(int i,int j,int x){
if (i==j)
    A[i-1]=x;


}
int Diagonal::Get(int i,int j){
if (i==j)
    return A[i-1];
return 0;
}

void Diagonal:: Display(){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<Get(i,j)<<' ';
    }
    cout<<endl;
}

}

int main()
{
    Diagonal A(4);
    A.Set(1,1,3);
    A.Set(2,2,4);
    A.Set(3,3,0);
    A.Set(4,4,10);
    cout<<A.Get(1,1)<<endl;
    A.Display();
    return 0;
}
