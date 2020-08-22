#include <iostream>
//the 2 method we used for finding dublicate in an unsorted array can be used here
//1.memorry efficient
//2.Time efficient using Hash and counting

//3.(new method)using bits for doing our work (using merging and masking) we will do this
using namespace std;

int main()
{
    char A[]="findnnngifg";
    int i,H=0,x=0;
    for(i=0;A[i]!='\0';i++){

        x=1;
        x<<=(A[i]-97);

        if((x&H)>0){
            cout<<A[i];
        }
        else{

            H=H|x;
            }

    }



    return 0;
}
