
/*

Given height as input: 4
    1
   3 2
  6 5 4
 10 9 8 7
 7 8 9 10
  4 5 6
   2 3
    1
*/

#include<iostream>

using namespace std;

int main()
{
   int height,space,a=0,num=0,temp;
   cin>>height;
   int h = height;
   while(h--)
   {
      ++a;
      num +=a;
      temp=num;
      for(int i=0;i<h;i++)
         cout<<" ";
      for(int j=a;j>0;j--)
      {
        cout<<temp<<" ";
        --temp;
      }
      cout<<"\n";
   }
   h = height;
   while(h--)
   {
      temp = num-a;
      for(int j=a;j>0;j--)
      {
        ++temp;
        cout<<temp<<" ";
        
      }
      cout<<"\n";
      num -= a;
      --a;
      for(int i=h;i<height;i++)
        cout<<" ";
      
   }
}
