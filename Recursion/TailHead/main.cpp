#include <iostream>

using namespace std;
//Head recursion
void Head(int n){
if(n>0){
    Head(n-1);
    cout<<n;

}
}
//tail recursion
void Tail(int n){
if (n>0){
    cout<<n;
    Tail(n-1);
}
}
int main()
{
    int a=3;
    Head(a);
    cout<<endl;
    Tail(a);
    return 0;
}
