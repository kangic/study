#include <cstdio>
#include <functional> // std::function

class test {
 public:
  test() = default;
  virtual ~test() = default;

  int on_call(int n) {
    return n + 10;
  }
};

int main() {
  test t;
  std::function<int(test&, int)> f = &test::on_call;
  printf("result = %d\n", f(t, 5));

  return 0;
}
