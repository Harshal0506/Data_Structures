#include <iostream>

using namespace std;

int fact(int n){
  if (n==0)
        return 1;
  return fact(n-1)*n;

}
 int com(int n,int r){
 int num=fact(n);
 int den=fact(r)*fact(n-r);
 return num/den;

 }

 int rcomb(int n ,int r){
 if (r==0 || r==n){
    return 1;
 }
 return rcomb(n-1,r-1)+rcomb(n-1,r);

 }

int main()
{
    cout << com(5,2)<< endl;
    cout<<com(5,2)<<endl;
    return 0;
}
