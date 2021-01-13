#include"Branch.h"

void Display(Branch obj) {
	obj.operator<<(cout);
}

int main() {
	cout << "hi";
	Branch obj;
	obj.menu();
	Display(obj);
}
