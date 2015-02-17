#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <string>

template<typename T>
class node {
public:
	node() {}

	T data;
	node* next;
};

template<typename T>
class linked_list {
public:
	linked_list(void);
	virtual ~linked_list(void);

	void insert_data(const T& data);
	void remove_data(const T& data);

	bool is_empty();

	int	size();
	const T& get_data(int pos);

	void clear();
	void display();

private:
	node<T>* create_list_node(const T& data);

	// vars
private:
	node<T>* head;

	int length;
};

#endif // _LINKED_LIST_H_

#include "linked_list.hpp"
