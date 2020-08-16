#include <iostream>

using namespace std;

void Tree(int n){
    if (n>0){
        cout<<n;
        Tree(n-1);
        Tree(n-1);
    }

}

int main()
{
    int a=3;
    Tree(a);

}
