#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int Size;
    int Length;
public:
     Array(int n){
        Size=n;
        A=new int[Size];

    }
    void Create(){
    cout<<"Enter the number of element you want to insert"<<endl;
    cin>>Length;
    cout<<"Enter the element of the array"<<endl;
    for (int i=0;i<Length;i++){
        cout<<"Array Element"<<i<<endl;
        cin>>A[i];
    }
    }
    void Display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    }
    ~Array(){
    delete []A;
    A=NULL;
    }




};
int main()
{
    int n;
    cout<<"Enter the size of the Array you Want"<<endl;
    cin>>n;
    Array A(n);
    A.Create();
    A.Display();
    return 0;
}
