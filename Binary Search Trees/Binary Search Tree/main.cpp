#include <iostream>

using namespace std;

class Node{
public:
 struct Node* lchild;
 int data;
 struct Node* rchild;


};

class BST{
private:
    Node* root;
public:
    BST(){ root= nullptr;}
    Node* getRoot(){return root;}
    void Insert(int key);
    void Inorder(Node *p);
    Node* Search(int key);


};

void BST::Insert(int key){
    struct Node* t=root;
    struct Node*p;
    struct Node *r=NULL;
    if(t == nullptr){
        p=new Node;
        p->data=key;
        p->lchild=NULL;
        p->rchild=NULL;
        root=p;
        return ;

    }
    while(t!=nullptr){
        r=t;
        if(key < t->data){
                t=t->lchild;

        }else if(key > t->data){
            t=t->rchild;

        }else{
            return;
        }


    }
    //now t points at Null and r points at insert location
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(r->data>key)
        r->lchild=p;
    else{
        r->rchild=p;
    }





}

void BST::Inorder(Node*p){
if(p){
    Inorder(p->lchild);
    printf("%d ,",p->data);
    Inorder(p->rchild);
}


}

Node * BST::Search(int Key){
    Node* t=root;
    while(t!=nullptr){
        if(t->data==Key){
            return t;
        }
        if(t->data<Key){
            t=t->rchild;
        }else{
            t=t->rchild;
        }



    }
    return nullptr;





}



int main()
{
      BST bst;

    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Search
    Node* temp = bst.Search(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
