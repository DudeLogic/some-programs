/*

Rotate the rows and colums in an n*n matrix;
Note:-row rotation from left to right and column rotation from top to bottom

line 1: n, number of rows, number of colums
input:
4 2 3

1 2 3 4
5 6 7 8
9 1 1 3
4 5 7 8

2 2
1 2 3

Output :
4 5 7 4 
1 2 3 6 
7 8 5 3 
9 1 1 8 
*/


#include<iostream>
#include<unordered_map>
using namespace std;


void justswap_row(int x,int rot,int ar[][1000],int n)
{
   int temp=0;
   --x;
   while(rot--)
   {
      temp=ar[x][rot];
      ar[x][rot] = ar[x][--n];
      ar[x][n]= temp;
   }
   
}

void justswap_col(int rot,int x,int ar[][1000],int n)
{
  int temp =0;
  --x;
  while(rot--)
  {
    temp = ar[rot][x];
    ar[rot][x] = ar[rot][--n];
    ar[rot][x] = temp;
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    unordered_map<int,int> row_rot;
    unordered_map<int,int> col_rot;
    unordered_map<int,int>::iterator it;
    int N,temp1,temp2,count,pos,rot,num;
    long int R=0,C=0;
    cin>>N>>R>>C;
    cout<<N<<" "<<R<<" "<<C<<"\n"<<endl;
    int ar[1000][1000];
    
    for(int i=0;i<N;i++)
    {
      
      for(int j=0;j<N;j++)
        cin>>ar[i][j];
    }
    while(R--)
    {
      cin>>num;
      row_rot[num] = ++row_rot[num];
    }  
   while(C--)
   {
      cin>>num;
      col_rot[num] = ++col_rot[num];        
   }
   
    for(it=row_rot.begin();it!=row_rot.end();it++)
    {
        rot=it->second%N;
        if(rot)
        {
          if((N-rot) == rot)
          {
            justswap_row(it->first,rot,ar,N);
            continue;
          }
           count=N;pos=1;
           temp1=ar[it->first-1][0];
           while(count--)
           {
              pos  = (pos + rot)%N;
              if(!pos)
                pos=N;
                
              temp2 = ar[it->first-1][pos-1];
              ar[it->first-1][pos-1] = temp1;
              temp1=temp2;
           }
        }
    }
    for(it=col_rot.begin();it!=col_rot.end();it++)
    {
        rot=it->second%N;
        if(rot)
        {
           count=N;pos=1;
           temp1=ar[0][it->first-1];
           if((N-rot) == rot)
          {
            justswap_col(rot,it->first,ar,N);
            continue;
          }
           while(count--)
           {
              pos  = (pos + rot)%N;
              if(!pos)
                pos=N;
                
              temp2 = ar[pos-1][it->first-1];
              ar[pos-1][it->first-1] = temp1;
              temp1=temp2;
           }
        }
    }
    
    for(int i=0;i<N;i++)
    {
       for(int j=0;j<N;j++)
         cout<<ar[i][j]<<" ";
         
       cout<<endl;
    }
    
}


/*Alternate my solution (It works)


    #include<iostream>
    #include<unordered_map>
    using namespace std;
     
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        unordered_map<int,int> row_rot;
        unordered_map<int,int> col_rot;
        unordered_map<int,int>::iterator it;
        int N,temp1,temp2,count,pos,rot,num;
        long int R=0,C=0;
        cin>>N>>R>>C;
        int store[N];
        int ar[N][N];
        
        for(int i=0;i<N;i++)
        {
          
          for(int j=0;j<N;j++)
            cin>>ar[i][j];
        }
        while(R--)
        {
          cin>>num;
          row_rot[num] = ++row_rot[num];
        }  
       while(C--)
       {
          cin>>num;
          col_rot[num] = ++col_rot[num];        
       }
       
        for(it=row_rot.begin();it!=row_rot.end();it++)
        {
            rot=it->second%N;
            if(rot)
            {
              
              for(count=1;count<=N;count++)
              {
                 pos = (count + rot)%N;                
                 if(!pos)
                   pos=N;
                 store[pos-1] = ar[it->first-1][count-1];
              }
              for(count=0;count<N;count++)
              ar[it->first-1][count] = store[count];
            } 
        }
        for(it=col_rot.begin();it!=col_rot.end();it++)
        {
            rot=it->second%N;
            if(rot)
            {
              
              for(count=1;count<=N;count++)
              {
                 pos = (count + rot)%N;                
                 if(!pos)
                   pos=N;
                 store[pos-1] = ar[count-1][it->first-1];
              }
              for(count=0;count<N;count++)
              ar[count][it->first-1] = store[count];
            }
        }
        
        for(int i=0;i<N;i++)
        {
           for(int j=0;j<N;j++)
             cout<<ar[i][j]<<" ";
             
           cout<<endl;
        }
        
    }
*/

