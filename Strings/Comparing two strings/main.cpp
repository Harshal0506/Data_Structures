#include <iostream>

using namespace std;

int main()
{
    char A[]="Painting";
    char B[]="Painting";
    int i=0;
    for(;(A[i]!='\0' && B[i]!='\0');i++)
    {
        if (A[i]!=B[i])
            break;
    }
    if (A[i]==B[i])
        cout<<"equal";
    else if(A[i]<B[i])
        cout<<"smaller";
    else
        cout<<"Greater";

    return 0;
}
