#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#define MAX_SIZE	100

template <typename T>
class array_list {
 public:
  array_list(void);
  virtual ~array_list(void);

  void add_to_front(const T& data);
  void add_to_back(const T& data);

  void delete_data(int pos);

  bool is_empty();
  bool is_full();

  int	size();
  const T& get_data(int pos);

  void clear();
  void display();

 private:
  T list[MAX_SIZE];
  int length;
};

#endif // _ARRAY_LIST_H_

#include "array_list.hpp"
