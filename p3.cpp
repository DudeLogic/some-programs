/*
   count number of days in between a given range of date
   input
   12
   12
   2012
   12
   12
   2013
*/


#include<iostream>

using namespace std;

int check_leap(int y1)
{
    if(y1%400 == 0)
       return 1;
     else if(y1%100 == 0)
       return 0;
     else if(y1%4 == 0)
       return 1;
     else return 0;
}

int main()
{
   int d1,m1,y1,d2,m2,y2;
   int days=0;
   
   cin>>d1>>m1>>y1>>d2>>m2>>y2;
   	
   while(y1<y2-1)
   {       
     days +=365 + check_leap(y1);
     y1++;
   }
   
   while(m1<m2 || y1<y2)
   {
      if(m1 == 12)
      {
         days += 31;
         ++y1;
         m1=1;
      }
      else
      {
        switch(m1)
        {
         case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          days += 31;
          break;
        case 4: case 6: case 9: case 11:
          days += 30;
          break;
        case 2:
          days += check_leap(y1) + 28;
          break;
       }
       ++m1;
      }
     // cout<<days<<endl;	
   }
   days +=d2-d1;
   
   cout<<days<<endl;
   
}
