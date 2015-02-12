#include <iostream>

template <typename T>
array_list<T>::array_list(void) {
	this->length = 0;
}

template <typename T>
array_list<T>::~array_list(void) {

}

template <typename T>
void array_list<T>::add_to_front(const T& data) {
	for (int i=this->length; i>=0; --i) {
		this->list[i+1] = this->list[i];
	}

	this->list[0] = data;
	++this->length;
}

template <typename T>
void array_list<T>::add_to_back(const T& data) {
	this->list[this->length] = data;
	++this->length;
}

template <typename T>
void array_list<T>::clear() {
	for (int i=0; i<MAX_SIZE; ++i) {
		this->list[i] = 0;
	}

	this->length = 0;
}

template <typename T>
void array_list<T>::display() {
	for (int i=0; i<this->length; ++i) {
		std::cout << this->list[i] << std::endl;
	}
}
