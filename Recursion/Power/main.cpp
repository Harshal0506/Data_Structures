#include <iostream>

using namespace std;

int rpower(int m,int n){
    if (n==0)
        return 1;
    return rpower(m,n-1)*m;
}
//more efficient
int power(int m,int n){
    if (n==0){
        return 1;
    }
    else if (n%2==0){
        return power(m*m,n/2);
    }else{
        return m*power(m*m,(n-1)/2);
    }

}
int main()
{
    cout<<rpower(3,4)<<' '<<power(3,4);
    return 0;
}
