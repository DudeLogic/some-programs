/*
   proggram to find mean of the elements in a sub array of indices n1,n2

input...   
10 4
100000000 200000000 3000000000 400000000 50000000 600000000 7000000000 800000000 900000000 100000000 
1 3
2 4
2 5
1 10
*/

  // IMPLEMENTATION 1
/*#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
   long long int *ar;
   ar = (long long int*)malloc(sizeof(long long int));
   long int N,Q,n1,n2;
   long long int sum=0;
   cin>>N>>Q;
   
   for(long int t=0;t<N;t++)
     cin>>ar[t];
     
   while(Q--)
   {
       cin>>n1>>n2;
       for(long int i =n1-1;i<n2;i++)
           sum += ar[i];
       
       cout<<sum/(n2-(n1-1))<<endl;
       sum=0;
   }
}*/

//idk first one causes segmentation fault @ larger inputs.

//IMPLEMENTATION 2. o/p took approx 2 sec.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
   long int N,Q,n1,n2,num;
   cin>>N>>Q;
   long long int ar[N];
   cin>>ar[0];
   for(long int t=1;t<N;t++)
   {
     cin>>num;
     ar[t] = ar[t-1]+num;
   } 
   while(Q--)
   {
       cin>>n1>>n2;
       if(n1 == 1)
         cout<<ar[n2-1]/n2<<endl;
       else 
         cout<<(ar[n2-1]-ar[n1-2])/(n2-(n1-1))<<endl;
   }
}




//SOMEONE'S IMPLEMENTATION (DOES THE SAME THING ABOVE in <.5sec).
//WOW CODE
/*
    #include <iostream>
    #include <string>
    #include <map>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
     
    typedef uint64_t BIGINT;
    //typedef __int128 BIGINT;
     
    #define BUFSIZE 1000000
    #define GETBUF\
    	p= nextptr;\
    	for( ; *p != '\n'; ++p );\
    	 nextptr= p + 1;--p;
     
    std::vector< uint64_t > fact= {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
     
    inline void get_num( char** p, uint64_t& val )
    {
    	auto fit= fact.begin( );
    	for( ; **p > 47 && **p < 58; --*p )
    		val+= ( **p - 48 ) * *fit++;
    }
     
    int main( )
    {
    	using std::cin;
    	//read the THING std::cin.........
    	char* buf= (char*)malloc( BUFSIZE );
    	size_t bufsize= BUFSIZE;
    	char* nextptr= buf;
    	for( ; !( cin.read( nextptr, BUFSIZE ).rdstate( ) & std::ios::eofbit ); )
    	{
    		bufsize+= BUFSIZE;
    		buf= (char*)realloc( (void*)buf, bufsize );
    		nextptr= buf + bufsize - BUFSIZE;
    	}
    	*( nextptr + cin.gcount( ) )='\n';
     
    	//load the thing data......
    	char*p;
    	nextptr= buf;
    	GETBUF; //nextptr,p
     
    	uint64_t Q( 0 );
    	get_num( &p, Q ); 
    	--p;
    	uint64_t N( 0 );
    	get_num( &p, N ); 
     
    	std::vector< uint64_t > ans( (unsigned int)Q );
    	std::vector< BIGINT >part( (unsigned int)N + 1 );
     
    	//the partial thing
    	GETBUF; //nextptr,p
    	BIGINT acc= 0;
    	auto pit= part.rbegin( );
    	for( ; pit != part.rend( ) - 1; ++pit )
    	{
    		auto fit= fact.begin( );
    		for( ; *p > 47 && *p < 58; --p )
    		//for( size_t i= 9; i; --i )
    			*pit+= ( *p - 48 ) * *fit++;
    		--p;
    	}
    	part.front( )= 0;
    	acc= 0;
    	for( auto& temp : part )
    		acc= ( temp+= acc );
     
    	//crunch the thing numbers
    	char* po= buf + 9;
    	for( auto& dest : ans )
    	{
    		GETBUF; //nextptr,p
    		uint64_t max( 0 );
    		uint64_t min( 0 );
    		get_num( &p, max );
    		--p;
    		get_num( &p, min );
    		BIGINT tempdest= ( part[ (unsigned int)max ] - part[ (unsigned int)min - 1 ] );
    		dest= tempdest / ( max - min + 1 );
    		*po--= '\n';
    		for( size_t i= 0; i < 9 ; ++i )
    		{
    			*po--= dest % 10 + '0';
    			dest/= 10;
    		}
    		po+= 20;
    	}
    	std::cout.write( buf, po - buf - 9 );
    	return 0;
    }

*/

