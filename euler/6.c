#include <stdio.h>

int main( int argc, char* argv[] )
{
	int sum = 0;
	int mul = 0;
	int i;

	for( i = 1; i <= 100; i++ )
	{
		sum += i;
		mul += ( i * i );
	}

	printf("value is %d\n", ( sum * sum ) - mul );

	return 0;

}
