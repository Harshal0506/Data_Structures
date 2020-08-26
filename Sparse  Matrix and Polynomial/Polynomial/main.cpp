#include <iostream>

using namespace std;

struct Term{
    int coeff;
    int exp;


};
struct Poly{
    int n;
    struct Term* A;


} ;

void Create(struct Poly *P){
    cout<<"Enter the Number of terms with non-zero coefficient"<<endl;
    cin>>P->n;
    P->A=new Term[P->n];
    cout<<"enter terms!!"<<endl;
    for(int i=0;i<P->n;i++)
        cin>>P->A[i].coeff>>P->A[i].exp;
}
void Display(struct Poly p)
{
 int i;
 for(i=0;i<p.n;i++)
    printf("%dx%d+",p.A[i].coeff,p.A[i].exp);
    cout<<'\b';
    cout<<"  "<<endl;
}

struct Poly* Add(struct Poly P1,struct Poly P2){
  struct Poly* Sum;
  Sum=new Poly;
  Sum->A=new Term[P1.n+P2.n];
  int i,j,k;
  i=j=k=0;
  while(i<P1.n && j<P2.n){
    if(P1.A[i].exp>P2.A[j].exp)
        Sum->A[k++]=P1.A[i++];
    else if(P1.A[i].exp<P2.A[j].exp)
        Sum->A[k++]=P2.A[j++];
    else{
        Sum->A[k]=P1.A[i++];
        Sum->A[k++].coeff+=P2.A[j++].coeff;
    }
}
for(;i<P1.n;i++)
    Sum->A[k++]=P1.A[i];
for(;j<P2.n;j++)
    Sum->A[k++]=P2.A[j];
Sum->n=k;
return Sum;







};






int main()
{
    struct Poly P1,P2,*P3;
    Create(&P1);
    Display(P1);
    Create(&P2);
    Display(P2);
    P3=Add(P1,P2);
    Display(*P3);
    return 0;
}
