#include <stdio.h>
unsigned int isPalindrome( unsigned int n )
{
	unsigned int palin1 = 0;
	unsigned int palin2 = n;

	while( palin2 != 0 )
	{
		palin1 = (palin1 * 10) + ( palin2 % 10 );
		palin2 = palin2 / 10;
	}

	return ( palin1 == n );
}

int main( int argc, char* argv[] )
{
	int i, j;
	unsigned int maxPalin = 0;

	for( i = 999; i >= 100; i-- )
	{
		if( ( i * i ) < maxPalin )
			break;

		for( j = i; j >= 100; j-- )
		{
			if( isPalindrome( i * j ) )
			{
				if( i * j > maxPalin )
					maxPalin = i * j;

				break;
			}
		}
	}

	printf("largest value is %d\n", maxPalin );

	return 0;
}

