#include "../array_list.h"

int main(void) {
	array_list<int> list;

	list.clear();

	list.add_to_back(100);
	list.add_to_back(30);
	list.add_to_front(40);
	list.add_to_front(70);
	list.add_to_back(80);

	list.display();

	return 0;
}
