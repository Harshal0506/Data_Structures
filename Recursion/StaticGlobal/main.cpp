#include <iostream>

using namespace std;
//working of static function
int fun(int n){

    static int i=0;
    if (n>0){
        i+=1;
        return fun(n-1)+i;
    }
    return 0;

}
//global function
int globalvar=0;
int global(int n){


    if (n>0){
        globalvar+=1;
        return global(n-1)+globalvar;
    }
    return 0;

}


int main()
{
    int a=fun(5);
    cout<<"static 1 call "<<a<<endl;
    a=fun(5);
    cout<<"static 2 call "<<a<<endl;

    a=global(5);
    cout<<"global 1 call "<<a<<endl;
     a=global(5);
    cout<<"global 2 call "<<a<<endl;
}
