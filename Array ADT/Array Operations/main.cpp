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

//student Programms

//find Missing Element


//1. missing 1 element from a sorted array starting from 1
int MissingSorted1(Array arr){
    int Sum=0;
    int m=Max(arr);
    for(int i=0;i<arr.Length;i++){
        Sum+=arr.A[i];
    }
    int AssumedSum=m*(m+1)/2;
    return AssumedSum-Sum;




}
//2. missing 1 element from a sorted array starting from any integer
int MissingSorted2(Array arr){
int diff=arr.A[0];
for(int i=1;i<arr.Length;i++){
    if(arr.A[i]-i!=diff){
        return i+diff;

    }

}


}
//3. Missing n element in a sorted array starting from any integer
void MissingSorted3(Array arr){
int diff=arr.A[0];
for(int i=1;i<arr.Length;i++){
    if(arr.A[i]-i!=diff){
        while(diff<arr.A[i]-i){
            cout<<i+diff<<' ';
            diff++;
        }
    }
}




}
//4.Missing element in an unsorted Array
void MissingUnsorted(Array arr){
    int m=Max(arr);
    int *H=new(int[m+1]);
    for(int i=0;i<m+1;i++){
        H[i]=0;
    }
    for(int i=0;i<arr.Length;i++){
        H[arr.A[i]]+=1;
    }
    for(int i=1;i<=Max(arr);i++){
        if(H[i]==0)
            cout<<i<<' ';
    }


    delete []H;


}

//finding Dublicates

//1.just finding dublicates in a sorted array(no counter)
void DublicateSorted(Array arr){
int previousDublicate=0;
for(int i=0;i<arr.Length-1;i++){
    if(arr.A[i+1]==arr.A[i] && arr.A[i]!=previousDublicate){
        cout<<arr.A[i]<<' ';
        previousDublicate=arr.A[i];
    }
}



}
//2.finding dublicates and counting it in a sortedArray

void DublicateSortedCounter(Array arr){
    int j;
 for(int i=0;i<arr.Length-1;i++){
    if (arr.A[i]==arr.A[i+1]){
        j=i+1;
        while(arr.A[j]==arr.A[i] && j<arr.Length)j++;
        cout<<arr.A[i]<<' '<<j-i<<endl;
        i=j-1;
    }
 }

}
//unsorted array(more general)
//3.finding just dublicates in an unsorted array(memory friendly takes more time)
void DublicateUnsortedCounter(Array arr){
    int Count;
for(int i=0;i<arr.Length-1;i++){

if(arr.A[i]!=-1){
    Count=1;
    for(int j=i+1;j<arr.Length;j++){
        if(arr.A[i]==arr.A[j]){
            Count+=1;
            arr.A[j]=-1;

        }
    }
    if(Count>1)
        cout<<arr.A[i]<<' '<<Count<<endl;
}
}



}
//3.finding just dublicates in an unsorted array(time friendly takes more memory)
void DublicateUnsortedCounter2(Array arr){
    int m=Max(arr);
    int *H=new(int[m+1]);
    for(int i=0;i<=m;i++){
        H[i]=0;
    }
    for(int i=0;i<arr.Length;i++){
        H[arr.A[i]]+=1;
    }
    for(int i=0;i<=m;i++){
        if(H[i]>1)
            cout<<i<<' '<<H[i]<<endl;
    }
    delete []H;
    H=NULL;
}

//finding pairs with sum K
//1.unsorted array implement using hash check another if there mark it precence and print the pair else just mark presence of other
//2. dont use memory and use time and check through all possible combination if sum is k using 2 pointer
//3.sorted array if sum=k I will implement this
void SortedSumK(Array arr,int k){
int i,j;
i=0;
j=arr.Length-1;
while(i<j){
    if (arr.A[i]+arr.A[j]==k){
        cout<<arr.A[i]<<' '<<arr.A[j]<<endl;
        i++;
        j--;
    }
    else if(arr.A[i]+arr.A[j]>k)
        j--;
    else
        i++;



}


}


int main()
{
/*
    struct Array arr1 {{},20,0};
    int ch,index,x;
    do
 {
 printf("\n\nMenu\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Search\n");
 printf("4. Sum\n");
 printf("5. Display\n");
 printf("6.Exit\n");

 printf("enter you choice ");
 scanf("%d",&ch);

 switch(ch)
 {
 case 1: printf("Enter an element and index");
 scanf("%d%d",&x,&index);
 Insert(&arr1,index,x);
 break;
 case 2: printf("Enter index ");
 scanf("%d",&index);
 x=Delete(&arr1,index);
 printf("Deleted Element is %d\n",x);
 break;
 case 3:printf("Enter element to search ");
 scanf("%d",&x);
 index=LinearSearch(arr1,x);
 printf("Element index %d",index);
 break;
 case 4:printf("Sum is %d\n",Sum(arr1));
 break;
 case 5:Display(arr1);

 }
 }while(ch<6);
*/  //menu driven Program

struct Array arr={{1,3,4,5,6,8,9,10,12,14},20,10};

SortedSumK(arr,9);










    return 0;
}
