#include <iostream>
#include <cassert>

#include "Stack.cpp"

using namespace std;

class Dish {
private:
	string description;

public:
	Dish() {
		this->description = "Default dish";
	}

	Dish(string description) {
		this->description = description;
	}

	string get_description() {
		return this->description;
	}
};

int main() {
	cout << "Tests starting. \n";

	Stack<Dish> dishStack = Stack<Dish>(5);

	assert(dishStack.current_size() == 0);
	//dishStack.pop(); // Should throw error
	//dishStack.peek(); // Should throw error

	dishStack.push(Dish("Dish 1"));
	assert(dishStack.current_size() == 1);
	dishStack.push(Dish("Dish 2"));
	assert(dishStack.current_size() == 2);
	dishStack.push(Dish("Dish 3"));
	assert(dishStack.current_size() == 3);
	dishStack.push(Dish("Dish 4"));
	assert(dishStack.current_size() == 4);
	dishStack.push(Dish("Dish 5"));
	assert(dishStack.current_size() == 5);
	dishStack.push(Dish("Dish 6")); // Should not work
	assert(dishStack.current_size() == 5);

	assert(dishStack.peek().get_description() == "Dish 5");
	assert(dishStack.pop().get_description() == "Dish 5");
	assert(dishStack.current_size() == 4);
	assert(dishStack.peek().get_description() == "Dish 4");
	assert(dishStack.pop().get_description() == "Dish 4");
	assert(dishStack.current_size() == 3);
	assert(dishStack.peek().get_description() == "Dish 3");
	assert(dishStack.pop().get_description() == "Dish 3");
	assert(dishStack.current_size() == 2);
	assert(dishStack.peek().get_description() == "Dish 2");
	assert(dishStack.pop().get_description() == "Dish 2");
	assert(dishStack.current_size() == 1);
	assert(dishStack.peek().get_description() == "Dish 1");
	assert(dishStack.pop().get_description() == "Dish 1");
	assert(dishStack.current_size() == 0);

	cout << "Tests done. \n";
}