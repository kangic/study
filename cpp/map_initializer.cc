#include <cstdio>
#include <map>
#include <string>

namespace test {
static std::map<int, std::string> test_map = {
  {0, "first"}
  , {1, "second"}
  , {2, "third"}
};

static const std::string& get_value(int no) {
  return test_map[no];
}

}
int main() {
  for (auto& it : test::test_map) {
    printf("%s\n", it.second.c_str());
  }

  printf("%s\n", test::get_value(2).c_str());
  return 0;
}
