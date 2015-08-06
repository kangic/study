#include <cstdio>

// Use the "using" keyword in place of the "typedef" keyword.
using cb_func = int(*)(int);

int callback_func(int value) {
  printf("called callback_func\n");
  return value + 10;
}

int func(int n, cb_func cb) {
  printf("called func\n");
  return cb(n + 10);
}

int main() {
  printf("result = %d\n", func(5, &callback_func));

  return 0;
}
