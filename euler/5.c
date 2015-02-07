#include <stdio.h>
int checkDivide( unsigned int value )
{
	int nDivide = 2;

	while( nDivide <= 20 )
	{
		if( ( value % nDivide ) != 0 )
			return 0;

		++nDivide;
	}

	return 1;
}


int main( int argc, char* argv[] )
{
	unsigned int nMaxValue = 20;

	while( 1 )
	{
		if( checkDivide( nMaxValue ) )
			break;

		++nMaxValue;
	}

	printf("Max Value is %d\n", nMaxValue );


	return 0;

}
