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
	node<T>* new_node = create_list_node(data);
	if (head == NULL) {
		head = new_node;
		new_node->next = NULL;
	}
	else {
		node<T>* iter_node;
		for (iter_node = head; iter_node != NULL; iter_node = iter_node->next) {
			if (iter_node->next == NULL) {
				iter_node->next = new_node;
				new_node->next = NULL;
			}
		}
	}

	++length;
}

template<typename T>
void linked_list<T>::remove_data(const T& data) {
	node<T>* prev_node = NULL;
	node<T>* iter_node = NULL;

	for (iter_node = head; iter_node != NULL; iter_node = iter_node->next) {
		if (iter_node->data == data) {
			prev_node->next = iter_node->next;
			break;
		}
		prev_node = iter_node;
	}

	if (iter_node != NULL) {
		delete iter_node;
		--length;
	}
}

template<typename T>
bool linked_list<T>::is_empty() {
	return length == 0;
}
template<typename T>
int	linked_list<T>::size() {
	return length;
}

template<typename T>
const T& linked_list<T>::get_data(int pos) {
	node<T>* find_node = head;

	while(pos--) {
		find_node = find_node->next;
	}

	return find_node->data;
}

template<typename T>
void linked_list<T>::clear() {
	for (node<T>* iter_node = head; iter_node != NULL; iter_node = iter_node->next) {
		if (iter_node != NULL) {
			delete iter_node;
		}
	}

	length = 0;
	head = NULL;
}

template<typename T>
void linked_list<T>::display() {
	node<T>* iter_node;
	for (iter_node = head; iter_node != NULL; iter_node = iter_node->next) {
		std::cout << iter_node->data << std::endl;
	}	
}

template<typename T>
node<T>* linked_list<T>::create_list_node(const T& data) {
	node<T>* new_node = new node<T>();

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

	
