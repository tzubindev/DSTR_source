#include <iostream>

using namespace std;

// array


// linked list


// queue


// stack
template <class T>

class Stack {
	T* list;
	int stackTop;
	int maxStackSize;

public:
	Stack(int MaxSize);
	~Stack();
	void push(T elem);
	T pop();
	T top();
	bool isEmpty();
};