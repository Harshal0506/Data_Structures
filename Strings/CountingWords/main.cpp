#include <iostream>

using namespace std;

int main()
{
    char A[]="How are  u                                  you";
    int i=0,Space=0;
    for(i=0;A[i]!='\0';i++){
        if(A[i]==' ' && A[i-1]!=' ')
            Space++;
    }

    cout << Space+1 << endl;
    return 0;
}
