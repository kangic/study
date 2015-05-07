#include <iostream>

template <typename T>
array_list<T>::array_list(void) {
  length = 0;
}

template <typename T>
array_list<T>::~array_list(void) {

}

template <typename T>
void array_list<T>::add_to_front(const T& data) {
  for (int i=length; i>=0; --i) {
    list[i+1] = list[i];
  }

  list[0] = data;
  ++length;
}

template <typename T>
void array_list<T>::add_to_back(const T& data) {
  list[length] = data;
  ++length;
}

template <typename T>
void array_list<T>::delete_data(int pos) {
  list[pos] = 0;

  if (pos != length) {
    for (int i=pos+1; i<length; ++i) {
      list[i-1] = list[i];
    }
    list[length] = 0;
  }

  --length;
}

template <typename T>
bool array_list<T>::is_empty() {
  if (length != 0)
    return false;

  return true;
}

template <typename T>
bool array_list<T>::is_full() {
  if (length != MAX_SIZE)
    return false;

  return true;
}

template <typename T>
int	array_list<T>::size() {
  return length;
}

template <typename T>
const T& array_list<T>::get_data(int pos) {
  return list[pos];
}

template <typename T>
void array_list<T>::clear() {
  for (int i=0; i<MAX_SIZE; ++i) {
    list[i] = 0;
  }

  length = 0;
}

template <typename T>
void array_list<T>::display() {
  for (int i=0; i<length; ++i) {
    std::cout << list[i] << std::endl;
  }
}
