#include <cstdio>

class calc {
 public:
  template<typename T>
  T sum(T a, T b) {
    return a + b;
  }
};  // calc class

int main(void) {
  calc c;
  printf("%d\n", c.sum(3, 4));
  printf("%.2f\n", c.sum(3.3, 4.4));

  return 0;
}
