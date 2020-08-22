#include <iostream>

//A string is not a array its a charracter array with null at the end
//You can read and print a string directly not as a array
//%s takes pointer to the string
//%c is used to print a character
//strings can be of type array or a type of literal
//no need of new keyword to allocate memory in heap charA[] in stack char *A in Heap
using namespace std;

int main()
{
    int i=0;
    char* S="Welcome";
    for(;S[i]!='\0';i++){

    }
    cout<<i<<endl;
    return 0;


    return 0;
}
