/*
   Ceaser cipher
   
 All-convoYs-9-be:Alert1.
4
*/
#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

char getchar(char ch,int l,int k,int n)
{
    return (char)(((((int)ch-l)+k)%n)+l);
}

int main()
{
    string str;
    int k,value;
    cin>>str;
    cin>>k;
    int size = str.length();
    for(int i=0;i<size;i++){
        
        if(isupper(str[i]))
          str[i] = getchar(str[i],65,k,26); 
        else if(islower(str[i]))
          str[i] = getchar(str[i],97,k,26);
        else if(isdigit(str[i]))
          str[i] = getchar(str[i],48,k,10);               
    }
    cout<<str<<endl;
}
