#include <iostream>
#include "Queues.h";
using namespace std;

Node *root =new Node;

void CreateTree(){
    Node *p;
    Node *t;
    int x;
    Queue q;
    create(&q,100);
    cout<<"Enter root value: \n";
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!IsEmpty(q)){
        p=dequeue(&q);
        cout<<"Enter Left Child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        cout<<"Enter Right Child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }






    }
    }

void preorder(Node* p){
    if (p){
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node* p){
    if (p){

        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}

void postorder(Node* p){
    if (p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}





int main()
{
    CreateTree();

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
    return 0;
}
