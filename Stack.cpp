#include <iostream>
#include <array>

using namespace std;

template<typename T>
class Stack {

public:
	Stack(int maxSize): MAX_STACK_SIZE(maxSize) {
		currentStackSize = 0;
		stackArray = new T[MAX_STACK_SIZE];
	}

	~Stack() {
		delete[] stackArray;
	}

	void push(T value) {
		if (full()) {
			cout << "Stack is full. Cannot push value.\n";
			return;
		}

		stackArray[currentStackSize] = value;
		currentStackSize++;
	}

	T pop() {
		if (currentStackSize == 0) {
			cerr << "Cannot pop an empty stack.\n";
			throw;
			return NULL;
		}

		T topValue = stackArray[currentStackSize - 1];
		currentStackSize--;

		return topValue;
	}

	T peek() {
		if (currentStackSize == 0) {
			cerr << "Cannot peek into an empty stack.\n";
			throw;
			return NULL;
		}

		T topValue = stackArray[currentStackSize - 1];

		return topValue;
	}

	bool empty() {
		return currentStackSize == 0;
	}

	bool full() {
		return currentStackSize == MAX_STACK_SIZE;
	}

	int current_size() {
		return currentStackSize;
	}

private:
	T* stackArray;
	int currentStackSize;
	const int MAX_STACK_SIZE;
};