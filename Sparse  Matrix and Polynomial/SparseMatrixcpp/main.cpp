#include <iostream>
using namespace std;
class Element
{
public:
 int i;
 int j;
 int x;
};
class Sparse
{
private:
 int m;
 int n;
 int num;
 Element *A;
public:
 Sparse(int m,int n,int num)
 {
 this->m=m;
 this->n=n;
 this->num=num;
 A=new Element[this->num];
 }
 ~Sparse()
 {
 delete [] A;
 }


 Sparse* operator+(struct Sparse S2);
 friend istream & operator>>(istream &is,Sparse &s);
 friend ostream & operator<<(ostream &os,Sparse &s);


};

Sparse* Sparse::operator+(struct Sparse S2){
        Sparse * Sum=new Sparse(m,n,num+S2.num);
        if ((m==S2.m)&&(n==S2.n)){
            int i,j,k;
            i=j=k=0;




            while(i<num && j<S2.num){
                if(A[i].i<S2.A[j].i)
                    Sum->A[k++]=A[i++];
                else if (A[i].i>S2.A[j].i)
                    Sum->A[k++]=S2.A[j++];
                else{
                    if(A[i].j<S2.A[j].j)
                        Sum->A[k++]=A[i++];
                    else if(A[i].j>S2.A[j].j)
                        Sum->A[k++]=S2.A[j++];
                    else{
                        Sum->A[k]=A[i++];
                        Sum->A[k++].x+=S2.A[j++].x;

                    }
                }


            }
            for(;i<num;i++)Sum->A[k++]=A[i];
            for(;j<S2.num;j++)Sum->A[k++]=S2.A[j];
            Sum->num=k;
            return Sum;


    }else
    return NULL;










}

 istream & operator>>(istream &is,Sparse &s)
 {
 cout<<"Enter non-zero elements"<<endl;
 for(int i=0;i<s.num;i++)
 is>>s.A[i].i>>s.A[i].j>>s.A[i].x;
 return is;
 }

 ostream & operator<<(ostream &os,Sparse &s)
 {
 int k=0;
 for(int i=1;i<=s.m;i++)
 {
 for(int j=1;j<=s.n;j++)
 {
 if(s.A[k].i==i && s.A[k].j==j)
 os<<s.A[k++].x<<" ";
 else
 os<<"0 ";
 }
 os<<endl;
 }
 return os;
 }

int main()
{
 Sparse S1(3,3,3);
 Sparse S2(3,3,3);

 cin>>S1;
 cin>>S2;



 cout<<"First Matrix"<<endl<<S1;
 cout<<"Second MAtrix"<<endl<<S2;
 Sparse * S3=S1+S2;
 cout<<"Sum is"<<endl<<*S3;


 return 0;
}
