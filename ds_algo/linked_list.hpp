#include <iostream>

template<typename T>
linked_list<T>::linked_list(void) {
	head = NULL;
	length = 0;
}

template<typename T>
linked_list<T>::~linked_list(void) {
}

template<typename T>
void linked_list<T>::insert_data(const T& data) {
	node<T>* tmp = create_list_node(data);
	if (head == NULL) {
		head = tmp;
	}
	else {
		
	}
}

template<typename T>
void linked_list<T>::remove_data(const T& data) {

}

template<typename T>
bool linked_list<T>::is_empty() {
	return length == 0;
}

template<typename T>
node<T>* linked_list<T>::create_list_node(const T& data) {
	node<T>* new_node = new node<T>(data);

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

	
