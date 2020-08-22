#include <iostream>

using namespace std;
//one method is reverse a string using another array
//compare these 2 array using compare opperation
int main()
{
    char A[]="kitti";
    int i,j;
    for(j=0;A[j]!='\0';j++){

    }
    j-=1;
    for(i=0;i<j;i++,j--){
        if(A[i]!=A[j]){
            cout<<"Not Palindrome";
            return 0;
        }
    }
    cout<<"Palindrome";
    return 0;
}
