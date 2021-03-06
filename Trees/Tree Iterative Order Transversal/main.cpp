//in recursion exit condition is needed and needed
//here height doesnot means height in tree terminology

#include <iostream>
#include "Queue.h"
#include <stack>

using namespace std;

class Tree
{
private:
 Node *root;
public:
 Tree(){root=NULL;}
 void CreateTree();
 void Preorder(){Preorder(root);}
 void Preorder(Node *p);
 void Postorder(){Postorder(root);}
 void Postorder(Node *p);
 void Inorder(){Inorder(root);}
 void Inorder(Node *p);
 void Heightorder(){Heightorder(root);}
 void Heightorder(Node *p);
 int Height(){return Height(root);}
 int Height(Node *root);


 void IterativePreorder(Node*p);
 void IterativePreorder(){IterativePreorder(root);}

 void IterativeInorder(Node*p);
 void IterativeInorder(){IterativeInorder(root);}

 void IterativePostorder(Node *p);
 void IterativePostorder(){IterativePostorder(root);}
};


void Tree::CreateTree()
{
 Node *p,*t=NULL;
 int x;
 Queue q(100);
 printf("Eneter root value ");
 scanf("%d",&x);
 root=new Node;
 root->data=x;
 root->lchild=root->rchild=NULL;
 q.enqueue(root);
 while(!q.isEmpty())
 {
 p=q.dequeue();
 printf("eneter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 q.enqueue(t);
 }
 printf("eneter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 q.enqueue(t);
 }
 }
}


void Tree::Preorder(struct Node *p)
{
 if(p)
 {

 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}

void Tree::Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);




    }

}

void Tree::Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}


void Tree::Heightorder(struct Node *p)
 {

 Queue q(100);
 printf("%d ",p->data);
 q.enqueue(p);
 while(!q.isEmpty())
 {
 p=q.dequeue();
 if(p->lchild)
 {
 printf("%d ",p->lchild->data);
 q.enqueue(p->lchild);
 }
 if(p->rchild)
 {
     printf("%d ",p->rchild->data);
    q.enqueue(p->rchild);
 }

 }
}

int Tree::Height(struct Node *root)
{

 int x=0,y=0;
 if(root==0)
 return 0;
 x=Height(root->lchild); y=Height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;
}


void Tree::IterativePreorder(struct Node *p){

stack <Node*> stk;
while(p || !stk.empty())
{
    if(p){
        cout<<p->data<<" ,";
        stk.push(p);
        p=p->lchild;

    }else{
        p=stk.top();
        stk.pop();
        p=p->rchild;


    }

}
cout<<endl;





}
void Tree::IterativeInorder(struct Node *p){

stack <Node*> stk;
while(p || !stk.empty())
{
    if(p){

        stk.push(p);
        p=p->lchild;

    }else{
        p=stk.top();
        stk.pop();
        cout<<p->data<<" ,";
        p=p->rchild;


    }

}
cout<<endl;





}


void Tree::IterativePostorder(struct Node *p){

stack <long long int> stk;
long long int temp;
while(p || !stk.empty())
{
    if(p){

        stk.push((long long int)p);
        p=p->lchild;

    }else{
        temp=stk.top();
        stk.pop();
        if(temp>0){
            stk.push(-temp);
            p=((Node *)temp)->rchild;



        }else{
            cout<< ((Node *)(-1*temp))->data<<", ";
            p=NULL;

        }


    }

}
cout<<endl;





}


int main()
{

    Tree t;
    t.CreateTree();
    cout<<"Preorder ";
    t.Preorder();
    cout<<endl;
    t.IterativePreorder();
    cout<<endl;
    cout<<"Inorder ";
    t.Inorder();
    cout<<endl;
    t.IterativeInorder();
    cout<<endl;
    cout<<"PostOrder ";
    t.Postorder();
    cout<<endl;
    t.IterativePostorder();
    cout<<endl;
    printf("Height is %d ",t.Height());
    return 0;

}
