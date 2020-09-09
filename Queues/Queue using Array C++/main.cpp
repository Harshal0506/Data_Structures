#include <iostream>

using namespace std;

class Queue{
private:
    int Size;
    int Front;
    int Rear;
    int *Q;
public:
    Queue(int s){
    Size=s;
    Q=new int [Size];
    Front=Rear=-1;


    }
    ~Queue(){
    delete []Q;

    }
    bool IsEmpty(){
        return Front==Rear;

    }
    bool IsFull(){
        return Rear==Size-1;
    }

    void enqueue(int x){
    if(IsFull())
        cout<<"Queue is Full"<<endl;
    else{
        Rear++;
        Q[Rear]=x;
    }
    }

    int dequeue(){
    int x=-1;
    if(IsEmpty())
        cout<<"Queue is Empty"<<endl;
    else{
        Front++;
        x=Q[Front];
    }
    return x;


    }

    void display();





};

void Queue::display(){
    for(int i=Front+1;i<=Rear;i++)
        cout<<Q[i]<<' ';
    cout<<endl;
}
int main()
{

    int A[] = {1, 3, 5, 7, 9};

    Queue q(sizeof(A)/sizeof(A[0]));

    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }

    // Display
    q.display();

    // Overflow
    q.enqueue(10);

    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }

    // Underflow
    q.dequeue();

    return 0;
}
