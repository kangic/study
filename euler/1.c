#include <stdio.h>

#define MAX_NUM 1000

int main( int argc, char* argv[] )
{
  int sum = 0;
  int i;
  int nMax = 0;

  if( argc > 1 )
    nMax = atoi( argv[1] );
  else
    nMax = MAX_NUM;

  for( i = 0; i < nMax; ++i )
  {
    if( ( ( i % 3 ) == 0 ) || ( ( i % 5 ) == 0 ) )
      sum += i;
  }

  printf( "sum = %d\n", sum );

  return 0;
}
