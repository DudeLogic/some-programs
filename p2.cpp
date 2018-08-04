#include<iostream>

using namespace std;

int main()
{
   int ar[4][5] = {{1, 2, 3, 4, 6}, {5, 3, 8, 1, 2}, {4, 6, 7, 5, 5}, {2, 4, 8, 9, 4} };
   int x1,y1,x2,y2,sum=0;
   cin>>x1>>y1>>x2>>y2;
   for(int i = x1;i<=x2;i++)
   {
     for(int j=y1;j<=y2;j++)
     {
      cout<<ar[i][j];
      sum +=ar[i][j];
     }
     cout<<endl;       
   }
   cout<<"\n"<<sum<<endl;
}
