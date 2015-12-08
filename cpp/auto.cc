#include <cstdio>
#include <memory>

class if_class {
 public:
  if_class() {
    printf("if_class\n");
  }
  virtual ~if_class() {
    printf("~if_class\n");
  }
};

class a_class : public if_class {
 public:
  a_class() {
    printf("a_class\n");
  }
  virtual ~a_class() {
    printf("~a_class\n");
  }
};

class b_class : public if_class {
 public:
  b_class() {
    printf("b_class\n");
  }
  virtual ~b_class() {
    printf("~b_class\n");
  }
};

using if_class_ptr = std::shared_ptr<if_class>;
using a_class_ptr = std::shared_ptr<a_class>;
using b_class_ptr = std::shared_ptr<b_class>;

class class_creator { 
 public:
  class_creator();
  virtual ~class_creator();

  auto create_class(int type) -> if_class_ptr {
    if (type == 1)
      return static_cast<if_class_ptr>(std::make_shared<a_class_ptr>(new a_class()));
  }
};

int main() {
  class_creator creator;
  if_class_ptr test = creator.create_class(1);

  return 0;
}
