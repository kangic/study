#include "../linked_list.h"

#include <iostream>

int main(void) {
	linked_list<int> list;

	list.clear();

	list.insert_data(100);
	list.insert_data(30);
	list.insert_data(40);
	list.insert_data(50);
	list.insert_data(10);
	list.insert_data(20);
	list.insert_data(80);
	list.insert_data(70);

	std::cout << "length = " << list.size() << std::endl;
	
	list.display();

	std::cout << "get_data(4) = " << list.get_data(4) << std::endl;

	list.remove_data(30);

	std::cout << "length = " << list.size() << std::endl;
	
	list.display();

	list.clear();

	std::cout << "clear..length = " << list.size() << std::endl;

	list.display();

	return 0;
}
