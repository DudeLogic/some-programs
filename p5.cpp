/*
   Find 3 most largest elements in an array
*/

#include<iostream>
#include<map>

using namespace std;

int main()
{
   int ar[] = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3};
   int n=13;
   map<int,int> elements;
   //cin>>n;
   for(int i=0;i<n;i++)
     elements[ar[i]]=0;
     
   for(int i=0;i<n;i++)
   {
      elements[ar[i]] = ++elements[ar[i]];
   }
   int l1=0,l2=0,l3=0;
   int c1=0,c2=0,c3=0,temp=0;
   map<int,int>:: iterator it = elements.begin();
   for(it;it!=elements.end();it++)
   {
     if(it->second > c1)
     {
       l3 = l2;
       l2 = l1;
       l1 = it->first;
       c3 = c2;
       c2 = c1;
       c1 = it->second;
        
     }
     else if(it->second >c2)
     {
       l3 = l2;
       l2 = it->first;
       c3 = c2;
       c2 = it->second;
     }
     else if(it->second >c3)
     {
       l3 = it->first;
       c3 = it->second;
     }
       
   }
   cout<<l1<<" "<<l2<<" "<<l3<<endl;
}
