/*
   Given two strings, a and b , that may or may not be of the same length, determine the minimum number of character deletions required to   make a and b anagrams. Any characters can be deleted from either of the strings.
   
 cde
 abc
 4
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int returncount(string str,unordered_map<char,int> &mapping)
{
   int size = str.length(),count=0;
   unordered_map<char,int> ::iterator it;
   for(int i=0;i<size;i++)
   {
     it = mapping.find(str[i]);
     if(it!=mapping.end())
     {
       
       if(it->second)
       {
          count+=2;
          mapping[it->first] = --mapping[it->first];
       }
     }
   }
   return count;
}

int main()
{
   unordered_map<char,int> mapping;
   int count=0,size1,size2,total=0;
   string str1,str2; 
   
   cin>>str1>>str2;
   size1 = str1.length(); size2 = str2.length();
   total = size1+size2;
   if(size1>size2)
   {
       for(int i=0;i<size2;i++)
         mapping[str2[i]] = 0;
         
       for(int j=0;j<size2;j++)
         mapping[str2[j]] = ++mapping[str2[j]];
         
        count = returncount(str1,mapping);
   }
   else
   {  
       for(int i=0;i<size1;i++)
         mapping[str1[i]] = 0;
         
       for(int j=0;j<size1;j++)
         mapping[str1[j]] = ++mapping[str1[j]];
         
       count = returncount(str2,mapping);
   }
   
   cout<<"\n"<<total-count<<endl;
}

