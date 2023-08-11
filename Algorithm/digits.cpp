#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  
  int temp=0;
  cin>>temp;

  //first way
  int a,b,c,d;
  a = temp/1000;
  b = (temp-a*1000)/100;
  c = (temp-a*1000-b*100)/10;
  d = (temp-a*1000-b*100-c*10);

  //second way
  int a2,b2,c2,d2;
  a2 = temp/1000;
  b2 = temp/100%10;
  c2 = temp/10%10;
  d2 = temp%10;

  cout<<a<<endl;
  cout<<b<<endl;
  cout<<c<<endl;
  cout<<d<<endl<<endl;

  cout<<a2<<endl;
  cout<<b2<<endl;
  cout<<c2<<endl;
  cout<<d2<<endl;

  return 0;
}