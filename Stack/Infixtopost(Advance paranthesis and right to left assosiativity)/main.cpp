/*
( has highest percedence outside but lowest inside

) has lowest percedence outside and andar it never enter

left to right associvity percedence increases as one enter into stack

right to left percedence decreases as one enter into stack percedence decreases (example power)
*/


#include <iostream>
#include<cstring>
#include <stack>

using namespace std;
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}


char * Convert(char * Infix){
char * Postfix=new char[strlen(Infix)+1];
stack <char> stk;
int i=0,j=0;
while(Infix[i]!='\0'){
    if(isOperand(Infix[i]))
        Postfix[j++]=Infix[i++];
    else{
    if(stk.empty()){
        stk.push(Infix[i++]);
        continue;
    }
    if(Infix[i]==')' && stk.top()=='(' ){
        stk.pop();
        i++;
        continue;
    }
    if(outPrecedence(Infix[i])>inPrecedence(stk.top()))
        stk.push(Infix[i++]);
    else if (outPrecedence(Infix[i])<inPrecedence(stk.top())){
        Postfix[j++]=stk.top();
        stk.pop();
    }






    }





}
while(!stk.empty()){
    Postfix[j++]=stk.top();
    stk.pop();
    }
Postfix[j]='\0';
return Postfix;
}



int main()
{
        char infix[] = "((a+b)*c)-d^e^f";

    cout << Convert(infix) << endl;
    return 0;
}
