#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
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

void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    Node* p;
    int x = -1;
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

int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}

int Stack::peek(int index) {
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
int IsOperand(char x){
if(x=='+'|| x=='-' || x=='*' || x=='/')
    return 0;
return 1;
}



int Operation(char a,int x1,int x2){
    if(a=='+')
        return x2+x1;
    if(a=='-')
        return x2-x1;
    if(a=='*')
        return x2*x1;
    return x2/x1;



}
int postfixEvaluate(char * postfix){
    struct Stack st;
    for(int i=0;postfix[i]!='\0';i++){
        if(IsOperand(postfix[i]))
            st.push(postfix[i]-'0');
        else{
            int x1,x2,r;
            x1=st.pop();
            x2=st.pop();
            r=Operation(postfix[i],x1,x2);
            st.push(r);



        }



    }



    return st.pop();

}

int main() {

     char postfix[] = "234*+82/-";

    cout << postfixEvaluate(postfix) << endl;

    return 0;


return 0;
}
