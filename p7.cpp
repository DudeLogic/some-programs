/*
  count the number of 1's in a binary number.
  1
  5
  output=2
*/


#include<iostream>

using namespace std;

int main()
{
   int t,n,temp,count=0;
   cin>>t;
   while(t--)
   {
     cin>>n;
     while(n)
     {
        temp = n&1;
        if(temp)
          ++count;
          
       n =  n>>1;
     }
      cout<<count<<endl;
      count = 0;
   }
}
