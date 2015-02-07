#include <stdio.h>

#define MAX_NUM 400 * 10000

unsigned long fibo( unsigned long fibo1, unsigned long fibo2 )
{
  unsigned long sum = 0;
  unsigned long iNext = 0;

  if( fibo1 > MAX_NUM )
    return 0;

  sum += ( ( ( fibo1 % 2 ) == 0 ) ? fibo1 : 0 );

  if( fibo2 > MAX_NUM )
    return sum;

  sum += ( ( ( fibo2 % 2 ) == 0 ) ? fibo2 : 0 );

  iNext = fibo1 + fibo2;

  return sum + fibo( iNex, iNext + fibo2 );
}

int main( int argc, char* argv[] )
{
  printf("result = %lu\n", fibo(1, 2));

  return 0;
}
