#include <iostream>

using namespace std;
//more space in stack
int sum(int n){
    if (n==0){
        return 0;
    }
    else{
        return sum(n-1)+n;
    }

}
int Isum(int n){
    int sum=0;
    for (int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
int main()
{   int a=5;
    cout <<Isum(a)<<endl;
    cout<<sum(a)<<endl;
    return 0;
}
