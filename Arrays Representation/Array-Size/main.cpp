#include <iostream>

using namespace std;

int main()
{
    int *p,*q;
    p=new(int[5]);
    p[0]=1;p[1]=2;p[2]=10;p[3]=9;p[4]=6;

    q=new(int[10]);
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete [] p;
    p=q;
    q=NULL;

    for(int i=0;i<5;i++){
        cout<<p[i]<<' ';
    }
    delete [] p;
    p=NULL;
    return 0;
}
