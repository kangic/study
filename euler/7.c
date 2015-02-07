#include <stdio.h>
#include <math.h>

int main( int argc, char* argv[] )
{
	int i = 2;
	int j;
	int count = 1;
	int isNotPrime;

	while( 1 )
	{
		isNotPrime = 0;

		++i;

		for( j = 2; j <= sqrt(i); j++ )
		{
			if( !(i%j) )
			{
				isNotPrime = 1;
				break;
			}
		}

		if( !isNotPrime )
			++count;

		if( count == 10001 )
			break;
	}

	printf("10001's prime number is %d\n", i );

	return 0;
}
