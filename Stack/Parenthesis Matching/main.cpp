#include <iostream>
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



int isBalanced( char *exp){
    struct Stack S;

    for(int i=0;exp[i]!='\0';i++){
    if(exp[i]=='(')
        S.push('(');
    else if(exp[i]==')'){
        if(S.isEmpty())
            return 0;

        S.pop();
    }
}
    if(S.isEmpty())
        return 1;
    cout<<"out"<<endl;
    return 0;

}

int AdvanceIsBalanced(char *exp){
    struct Stack  S;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            S.push(exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(S.isEmpty())


                 return 0;


            else{
                if(exp[i]-S.stackTop() ==1 || exp[i]-S.stackTop()==2)
                    S.pop();
                else

                    return 0;



            }

        }




    }
    if(S.isEmpty())
        return 1;

    return 0;











}






int main() {
    char A[] = "{([a+b]*[c-d])/e}";
    cout << AdvanceIsBalanced(A) << endl;

    char B[] = "{([a+b]}*[c-d])/e}";
    cout << AdvanceIsBalanced(B) << endl;

    char C[] = "{([{a+b]*[c-d])/e}";
    cout << AdvanceIsBalanced(C) << endl;
}
