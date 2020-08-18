#include <iostream>

using namespace std;



int main()
{
    //Here Continuous block of memory
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int n=0;

    //An Array of int* in Stack
    int *C[3];
    C[0]=new int[4];
    C[1]=new int[4];
    C[2]=new int[4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++,n++)
            C[i][j]=n;


    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
            cout<<C[i][j]<<' ';
        cout<<endl;

    }



    n=0;
    //Just B in Stack else in Heap
    int **B=new int*[3];
    B[0]=new int[4];
    B[1]=new int[4];
    B[2]=new int[4];



    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++,n++)
            B[i][j]=n;


    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
            cout<<B[i][j]<<' ';
        cout<<endl;

    }
    //free the space on your own
    return 0;

}
