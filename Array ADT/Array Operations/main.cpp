#include <iostream>

using namespace std;

struct Array {
 int A[20];
 int Size;
 int Length;


};
void Display(struct Array arr){
    for(int i=0;i<arr.Length;i++){
        cout<<arr.A[i]<<' ';

    }
    cout<<endl;
}
void Append(struct Array *arrptr,int x){
  if (arrptr->Length!=arrptr->Size){
    arrptr->A[arrptr->Length]=x;
    arrptr->Length+=1;

  }

}
void Insert(struct Array *arrptr,int index,int x){
    if (index>=0 && index<=arrptr->Length){
     int i=arrptr->Length;
     for (;i>index;i--){
        arrptr->A[i]=arrptr->A[i-1];

     }
     arrptr->A[i]=x;
     arrptr->Length++;

    }


}

int  Delete(struct Array *arrptr,int index){
    if(index>=0 && index<arrptr->Length){
        int i=index;
        int x=arrptr->A[index];

        for(;i<arrptr->Length-1;i++){
            arrptr->A[i]=arrptr->A[i+1];
        }
        arrptr->Length--;
        return x;

    }

}

int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.Length;i++){
        if (key==arr.A[i])
            return i;

    }
    return -1;


}


//improved Linear Search (transposition and Move to Head) Here i m using Move to Head
void Swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;


}
int ImprovedLinearSearch(struct Array *arrptr,int key){
    for (int i=0;i<arrptr->Length;i++){
        if (key==arrptr->A[i]){
            Swap(&arrptr->A[i],&arrptr->A[0]);
            return 0;
        }

    }
    return -1;
}

int main()
{

    struct Array arr {{2,3,4,5,4},20,5};
    Display(arr);
    cout<<ImprovedLinearSearch(&arr,5)<<endl;
    Display(arr);


    return 0;
}
