#include <cstdio>
#include <memory> // shared_ptr, unique_ptr
#include <thread>
#include <vector>

class auto_delete {
 public:
  auto_delete(int n) {
    _n = n;
    printf("<%d> constructor!!\n", _n);
  }

  virtual ~auto_delete(void) {
    printf("<%d> destructor!!\n", _n);
  }

  void do_something(void) {
    printf("<%d> do something~~!!\n", _n);
  }

 private:
  int _n;
};

void loop1(std::vector<std::shared_ptr<auto_delete>> vec) {
  // No effect to delete the element in vec.
  auto iter = vec.begin();
  vec.erase(iter); 

  printf("=== end of the loop1 ===\n");
}

void loop2(void) {
  printf("=== vector 2 ===\n");
  std::vector<std::shared_ptr<auto_delete>> vec2;
  for (auto i=21; i<30; ++i) {
    vec2.emplace_back(new auto_delete(i)); 
  }

  // should be called destructor of the end of the vector's elements.
  // I think using the shared_ptr is important to design the scope.
  auto iter = vec2.end();
  vec2.erase(iter); 

  printf("=== end of the loop2 ===\n");
}

int main(void) {
  // unique_ptr do not count the reference counting.
  // it delete the pointer when leave the scope.
  std::unique_ptr<auto_delete> ad1(new auto_delete(1));
  {
    std::unique_ptr<auto_delete> ad2(new auto_delete(2));
    ad2->do_something(); 
  }
  ad1->do_something();

  printf("=== vector 1 ===\n");
  std::vector<std::shared_ptr<auto_delete>> vec1;
  for (auto i=11; i<20; ++i) {
    vec1.emplace_back(new auto_delete(i)); 
  }

  // need the "-pthread" option when compile this source
  std::thread th1(loop1, vec1);
  std::thread th2(loop2);
  th1.join();
  th2.join();

  return 0;
}
