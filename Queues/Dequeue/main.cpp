#include <iostream>

using namespace std;

class DEQueue{
private:
    int Size;
    int Front;
    int Rear;
    int *Q;
public:
    DEQueue(int s);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueBack(int x);
    int dequeueFront();
    int dequeueBack();
    bool IsEmpty();
    bool IsFull();
};

DEQueue::DEQueue(int s){
Size=s;
Q=new int[Size];
Front=Rear=-1;
}

DEQueue::~DEQueue(){
    delete []Q;

}
bool DEQueue::IsEmpty(){

    return Front==Rear;
}

bool DEQueue::IsFull(){
if(Rear==Size-1 && Front==-1)
    return true;
return false;
}

void DEQueue::enqueueFront(int x){
    if(Front ==-1)
        cout<<"DEqueue Overflow";
    else{
        Q[Front]=x;
        Front --;
    }
}
void DEQueue::enqueueBack(int x){
    if(Rear==Size-1)
        cout<<"DEqueue Overflow";
    else{
        Rear++;
        Q[Rear]=x;
    }
}

int DEQueue::dequeueFront(){
    int x=-1;
    if(Front==Rear)
        cout<<"DEQueue Underflow";
    else{
        Front ++;
        x=Q[Front];


    }
    return x;

}

int DEQueue::dequeueBack(){
    int x=-1;
    if(IsEmpty())
        cout<<"DEQueue Underflow";
    else{
        x=Q[Rear];
        Rear--;


    }
    return x;
}

void DEQueue::display() {
    for (int i=Front+1; i<=Rear; i++) {
        cout << Q[i] << flush;
        if (i < Rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}


int main()
{

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQueue deq(sizeof(A)/sizeof(A[0]));

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueBack(A[i]);
    }
    deq.display();
    deq.enqueueBack(11);

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();

    cout << endl;

    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();

    deq.enqueueFront(10);
    deq.enqueueFront(12);

    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueBack();
    }
    deq.display();
    deq.dequeueBack();
    deq.dequeueBack();

    return 0;


}
