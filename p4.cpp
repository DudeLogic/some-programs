/*
check a given word contains the words in a dictionary
(this pgm has two solutions)
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

void efficient(string, string);	

int main()
{
   string s1,s2,s3;
   cin>>s1>>s2;
   int k=0;	
   for(int i=0;i<s2.length();i++)
   {
      for(int j=0;j<s1.length();j++)
      {
         if(s1[j] != s2[i])
         {
           s3 += s1[j];
         }
      }
      s1 = s3;
      s3.clear();
   }
  // cout<<s1<<endl;
  efficient(s1,s2);
}

void efficient(string s1, string s2)
{
     map<char,int> mapping;
     string s3;
     map<char,int>::iterator it;
     for(int i=0;i<s2.length();i++)
        mapping[s2[i]] = i;
        
     for(int j=0;j<s1.length();j++)
     {
       if(mapping.find(s1[j]) == mapping.end())
         s3+=s1[j];
     }
     cout<<s3<<endl;
}

