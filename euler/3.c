#include <stdio.h>
#include <math.h>

#define PRIME_NUM 600851475143

int isPrime( unsigned long n )
{
     unsigned long i, sqrn;
     sqrn = (unsigned long)sqrt(n);
     for( i = 2; i <= sqrn; i++ )
         if( ( n % i ) == 0 )
             return 0;

     return 1;
}

int main( int argc, char* argv[] )
{
     unsigned long nDivideNum = sqrt(PRIME_NUM);
	 
	     if( ( nDivideNum % 2 ) == 0 )
	         --nDivideNum;

     while( 1 )
     {
         if( ( ( PRIME_NUM % nDivideNum ) == 0 ) && isPrime( nDivideNum ) )
         {
             break;
         }

         nDivideNum -= 2;
     }

     printf( "Max Prime Number = %lu\n", nDivideNum );

	 return 0;
}
