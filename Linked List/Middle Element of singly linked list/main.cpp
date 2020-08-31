#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head = new Node;

void create(int A[], int n){
    Node* temp;
    Node* tail;

    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (int i=1; i<n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }
}

void middleNode1(Node* p){
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    int index=ceil(length/2.0);
    p=head;
    for(int i=1;i<=index-1;i++)
        p=p->next;
    cout << "Middle Element (Method-I): " << p->data << endl;
}

void middleNode2(Node* p){
    Node* q = p;
    while (q){
        q = q->next;
        if (q){
            q = q->next;
        }
        if (q){
            p = p->next;
        }
    }
    cout << "Middle Element (Method-II): " << p->data << endl;
}

void middleNode3(Node* p){
    stack<Node*> s;
    while (p){
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int popLength =(floor(length/2.0));
    while (popLength){
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
}


int main() {

    int A[] = {1,2,3,4};
    create(A,4);

    cout << endl;
    middleNode1(head);
    middleNode2(head);
    middleNode3(head);

    return 0;
}
