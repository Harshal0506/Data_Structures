#include <iostream>
#include<cstring>
using namespace std;

class Node{
public:
    char data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(char x);
    char pop();
    char peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(char x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop() {
    Node* p;
    char x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 0: 1;
    delete t;
    return r;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

char Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}

char Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;

        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }

        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}

int pre(char x){
if(x=='+' || x=='-')
    return 1;
else if(x=='*'|| x=='/')
    return 2;

    return 0;

}

int IsOperand(char x){
if(x=='+'|| x=='-'|| x=='/' || x=='*')
    return 0;
return 1;



}

char * InToPost(char *infix){
 char * postfix=new char[strlen(infix)+1];
 int i=0,j=0;
 struct Stack s;
 while(infix[i]!='\0'){
    if(IsOperand(infix[i]))
        postfix[j++]=infix[i++];
    else{
        if(s.isEmpty())
            s.push(infix[i++]);
        else{
            if(pre(s.stackTop())<pre(infix[i]))
            s.push(infix[i++]);
            else{
                postfix[j++]=s.pop();
            }
    }
    }
    }
while(!s.isEmpty())
    postfix[j++]=s.pop();
postfix[j]='\0';
return postfix;





}

int main(){
char *infix="a+b+c-d";


 char *postfix=InToPost(infix);

 printf("%s ",postfix);


 return 0;



return 0;
}
