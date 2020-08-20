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

int BinarySearch(struct Array arr,int Key){
  int l=0;
  int h=arr.Length-1;
  int mid=0;
  while(l<=h){
    mid=(l+h)/2;
    if(arr.A[mid]==Key)
    return mid;
    else if (arr.A[mid]<Key)
        l=mid+1;
    else{
        h=mid-1;
    }

  }
  return -1;


}

int RBinarySearch(struct Array arr,int l,int r,int Key){
    if (l<=r){
        int mid=(l+r)/2;
        if (arr.A[mid]==Key)
            return mid;
        else if (arr.A[mid]>Key)
                return RBinarySearch(arr,l,mid-1,Key);
        else
                return RBinarySearch(arr,mid+1,r,Key);

    }
    return -1;

}

int Get(struct Array arr,int index){
    if (index>=0 && index<arr.Length){
        return arr.A[index];
    }
    return -1;


}

void  Set(struct Array *arrptr,int index,int x){
    if (index>=0 && index<arrptr->Length){
         arrptr->A[index]=x;
    }



}

int Max(struct Array arr){
    int m=arr.A[0];
    for(int i=1;i<arr.Length;i++){
        if(arr.A[i]>m)
            m=arr.A[i];

    }
    return m;

}
int Min(struct Array arr){
    int m=arr.A[0];
    for(int i=1;i<arr.Length;i++){
        if(arr.A[i]<m)
            m=arr.A[i];

    }
    return m;

}

int Sum(struct Array arr){
    int Sum=0;
    for(int i=0;i<arr.Length;i++){
        Sum+=arr.A[i];
    }
    return Sum;

}
float Avg(struct Array arr){
    int s=Sum(arr);
    return (float)s/arr.Length;

}

void Reverse(struct Array *arrptr){
    int *B=new int [arrptr->Length];
    int i,j;
    for(i=0,j=arrptr->Length-1;j>=0;i++,j--){
        B[i]=arrptr->A[j];

    }
    for(i=0;i<arrptr->Length;i++){
        arrptr->A[i]=B[i];
    }




}
void Reverse2(struct Array *arrptr){
    int i,j;
    for(i=0,j=arrptr->Length-1;j>i;i++,j--){
        Swap(&arrptr->A[i],&arrptr->A[j]);
    }
}
void InsertSorted(struct Array *arrptr,int x){
if(arrptr->Length==arrptr->Size)
    return;

 int i=arrptr->Length-1;
 while(i!=-1&&arrptr->A[i]>x){
    arrptr->A[i+1]=arrptr->A[i];
    i--;
 }
 arrptr->A[i+1]=x;
 arrptr->Length++;


}
bool IsSorted(struct Array arr){
 int i;
 for(i=0;i<arr.Length-1;i++){
    if (arr.A[i+1]<arr.A[i])
        return false;
 }
 return true;

}

void Rearrange(struct Array *arrptr){
 int i,j;
 i=0;
 j=arrptr->Length-1;
 while(i<j){
    while(arrptr->A[i]<0)
        i++;
    while(arrptr->A[j]>0)
        j--;
    if (i<j){
        Swap(&arrptr->A[i],&arrptr->A[j]);
    }
 }

}

//merging 2 arrays
Array* Merge(struct Array arr1,struct Array arr2){
    int i,j,k;
    i=j=k=0;

    Array* C=new(struct Array);
    C->Size=20;
    while(i<arr1.Length&&j<arr2.Length){
        if (arr1.A[i]<arr2.A[j])
            C->A[k++]=arr1.A[i++];
        else{
            C->A[k++]=arr2.A[j++];
        }
    }
    for(;i<arr1.Length;i++){
        C->A[k++]=arr1.A[i];
    }
    for(;j<arr2.Length;j++){
        C->A[k++]=arr2.A[j];
    }

    C->Length=k;
    return C;






}
//set Operation in a sorted Array as it is more efficient

Array* SortedUnion(struct Array arr1,struct Array arr2){
    Array* C=new Array;
    C->Size=20;
    int i,j,k;
    i=j=k=0;
    while(i<arr1.Length && j<arr2.Length){
        if (arr1.A[i]<arr2.A[j])
            C->A[k++]=arr1.A[i++];
        else if (arr2.A[j]<arr1.A[i])
            C->A[k++]=arr2.A[j++];
        else{
            C->A[k++]=arr1.A[i++];
            j++;
        }


    }
    for(;i<arr1.Length;i++)
        C->A[k++]=arr1.A[i];
    for(;j<arr2.Length;j++)
        C->A[k++]=arr2.A[j];
    C->Length=k;
    return C;



}

Array* SortedIntersection(Array arr1,Array arr2){
    Array* C=new Array;
    C->Size=20;
    int i,j,k;
    i=j=k=0;
    while(i<arr1.Length && j<arr2.Length){
        if(arr1.A[i]<arr2.A[j]){
            i++;
        }
        else if(arr2.A[j]<arr1.A[i]){
            j++;
        }else{
        C->A[k++]=arr1.A[i++];
        j++;


        }

    }
    C->Length=k;
    return C;



}

Array* SortedDifference(struct Array arr1,struct Array arr2){
    Array* C=new Array;
    C->Size=20;
    int i,j,k;
    i=j=k=0;
    while(i<arr1.Length && j<arr2.Length){
        if(arr1.A[i]>arr2.A[j])
            j++;
        else if(arr1.A[i]<arr2.A[j]){
            C->A[k++]=arr1.A[i++];
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1.Length;i++)
        C->A[k++]=arr1.A[i];
    C->Length=k;
    return C;



}

int main()
{

    struct Array arr1 {{7,9,18,21,22},20,5};
    Display(arr1);
    struct Array arr2 {{7,9,18,21,28},20,5};
    Display(arr2);
    struct Array *arr3=SortedDifference(arr1,arr2);
    Display(*arr3);











    return 0;
}
