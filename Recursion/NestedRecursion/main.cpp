#include <iostream>

using namespace std;

int Nested(int n){
    if (n>100){
        return n-10;
    }
    return Nested(Nested(n+11));


}
int main()
{
int a=120;
cout<<Nested(a);
}
