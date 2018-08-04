/*
   print all the possible combinations of a string
   hint:- total possible combinations is n*(n-1)
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int count=0;
  while(count<(s.length()*(s.length()-1)))
  {
     for(int i=0;i<s.length()-1;i++)
     {
        char temp = s[i];
        s[i]  = s[i+1];
        s[i+1]= temp;
        cout<<s<<endl;
        count++;
     }
  }
cout<<count<<endl;  
}
