/*
Given two strings of equal length, you have to tell whether they both strings are identical. 
3
sumit
mitsu
ambuj
jumba
abhi
hibb

o/p

YES
YES
NO

*/

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
  int T,size,i;
  string str;
  unordered_map<char,int> mapping1,mapping2;
  unordered_map<char,int>:: iterator it;
  cin>>T;
  while(T--)
  {
     cin>>str;
     size = str.size();
     for(i=0;i<size;i++)
       mapping1[str[i]] = 0;
       
    for(i=0;i<size;i++)
       mapping1[str[i]] = ++mapping1[str[i]];
       
    cin>>str;
    for(i=0;i<size;i++)
       mapping2[str[i]] = 0;
       
    for(i=0;i<size;i++)
       mapping2[str[i]] = ++mapping2[str[i]] ;
       
   for(it = mapping1.begin();it!=mapping1.end();it++)
   {
       if(mapping2.find(it->first) == mapping2.end()) 
       {
          cout<<"NO"<<endl;
          break;
       }
       else if((mapping2.find(it->first))->second != it->second)
       {
          cout<<"NO"<<endl;
          break;
       }
   }
   if(it==mapping1.end())
     cout<<"YES"<<endl;
   
   mapping1.clear(); mapping2.clear();
            
  }
}
