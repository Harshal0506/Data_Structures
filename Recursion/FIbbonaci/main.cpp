#include <iostream>

using namespace std;

int Ifibonacii(int n){
    int t0,t1;
    t0=0;
    t1=1;
    if (n<2){
        return n;
    }
    int s;
    for (int i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return t1;

}


int Rfibonacii(int n){
    if (n<2)
        return n;
    return Rfibonacii(n-1)+Rfibonacii(n-2);

}
//recursive using memoization
int F[10];
int mfib(int n){
    if(n<2){

        return n;

    }
    else{
        if (F[n-1]==-1)
                F[n-1]=mfib(n-1);
        if (F[n-2]==-1)
               F[n-2]=mfib(n-2);
        return F[n-1]+F[n-2];

    }


}


int main()
{
    int i;
    for(i=0;i<10;i++)
        F[i]=-1;
    cout<<mfib(9)<<endl;

    cout << Ifibonacii(9) << endl;
    cout << Rfibonacii(9) << endl;

    return 0;
}
