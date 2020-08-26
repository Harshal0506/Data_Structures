#include <iostream>

using namespace std;
struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *A;



};

void Create(struct Sparse *S){

    cout<<"Enter Dimensions"<<endl;
    scanf("%d %d",&S->m,&S->n);
    cout<<"Number of Non-Zero Element"<<endl;
    scanf("%d",&S->num);
    S->A=new Element[S->num];
    cout<<"Enter Non-Zero Element"<<endl;
    for(int i=0;i<S->num;i++)
        scanf("%d %d %d",&S->A[i].i,&S->A[i].j,&S->A[i].x);


}
void Display(struct Sparse S){
int i,j,k=0;
for(i=1;i<=S.m;i++){
    for(j=1;j<=S.n;j++){
        if(S.A[k].i==i && S.A[k].j==j)
            cout<<S.A[k++].x<<' ';
        else
            cout<<"0 ";
    }
    cout<<endl;
}




}

struct Sparse* Add (struct Sparse S1,struct Sparse S2){
    if ((S1.m==S2.m)&&(S1.n==S2.n)){
            int i,j,k;
            i=j=k=0;

            struct Sparse* Sum=new Sparse;
            Sum->m=S1.m;
            Sum->n=S1.n;
            Sum->A=new Element[S1.num+S2.num];
            while(i<S1.num && j<S2.num){
                if(S1.A[i].i<S2.A[j].i)
                    Sum->A[k++]=S1.A[i++];
                else if (S1.A[i].i>S2.A[j].i)
                    Sum->A[k++]=S2.A[j++];
                else{
                    if(S1.A[i].j<S2.A[j].j)
                        Sum->A[k++]=S1.A[i++];
                    else if(S1.A[i].j>S2.A[j].j)
                        Sum->A[k++]=S2.A[j++];
                    else{
                        Sum->A[k]=S1.A[i++];
                        Sum->A[k++].x+=S2.A[j++].x;

                    }
                }


            }
            for(;i<S1.num;i++)Sum->A[k++]=S1.A[i];
            for(;j<S2.num;j++)Sum->A[k++]=S2.A[j];
            Sum->num=k;
            return Sum;


    }else
    return NULL;





};



int main()
{
    struct Sparse S1;
    Create(&S1);
    struct Sparse S2;
    Create(&S2);

    Display(*Add(S1,S2));


    return 0;
}
