/*
   Input First line of input contains an integer T number of test cases. Each test case contains an integer M (1 ≤ M ≤ 100,000) — the required number of trailing zeroes in factorial.

Output First print k — the number of values of n such that the factorial of n ends with m zeroes. Then print these k integers in increasing order.

i/p
1
1
o/P
5 6 7 8 9 
*/

#include<iostream>

using namespace std;

int main(){
    int T,m,temp;
    cin>>T;
    long long int num=1,f=24; //(4!)
    long int next=5,count,test=0;
    long long  int a[100],pos=0;
    while(T--)
    {
       cin>>m;
       temp=m;
       while(temp--)
        num *=10;
    
       do
       {
          f *= next++;
       }while(f<num);
      do
       {
         num = f;
         count=0;
         while(count<=m)
         {
            test = num%10;
            num /=10;
            if(!test)
              ++count;
            
            else break;
              
         }
         if(count == m)
           a[pos++] = next-1;
           
         f*= next++;
       } while(count<=m); 
       
       cout<<pos<<" "<<f<<endl;
       for(int i=0;i<pos;i++)
         cout<<a[i]<<" "; 
         
       cout<<endl;
     num=1;next=5;f=24,test=0,pos=0;
    }
    
}
