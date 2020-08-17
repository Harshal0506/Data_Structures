#include <iostream>

using namespace std;

double e(int x,int n){
    static double p=1;
    static double f=1;
    if (n==0)
        return 1;
    else{
        double r=e(x,n-1);
        p*=x;
        f*=n;
        return r+p/f;
    }

}

int main()
{
 cout<<e(4,15)<<endl;
 return 0;
}
