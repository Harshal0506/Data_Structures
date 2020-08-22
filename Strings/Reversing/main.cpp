#include <iostream>

using namespace std;

int main()
{
    char A[]="Python";
/*    char B[7];
    int i,j;
    for( i=0;A[i]!='\0';i++)
    {

    }
    i-=1;
    for( j=0;i>=0;i--,j++){
        B[j]=A[i];
    }
    B[j]='\0';

    for(int i=0;B[i]!='\0';i++){
        A[i]=B[i];
    }
    cout<<A;
*/
int i,j;

for(j=0;A[j]!='\0';j++){

}
j--;
for(i=0;i<j;i++,j--){
    int temp=A[j];
    A[j]=A[i];
    A[i]=temp;
}
cout<<A;


    return 0;
}
