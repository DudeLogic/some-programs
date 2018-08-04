/*
  couning number of concecutives 1's and 0's
*/
#include<iostream>

using namespace std;

int main()
{
    char ch;
    int count1=0,count0=0;
    while(cin>>ch)
    {
        if(ch=='0'){
          if(count0<6)
            ++count0;
            
          if(count0==6)
            break;
        } 
        else if(ch=='1')
          if(count1<6)
            ++count1;
          else if(count1==6)
            break;
    }
    if(count1==6 || count0==6)
      cout<<"Sorry, sorry!";
    else
      cout<<"Good luck!";
}
