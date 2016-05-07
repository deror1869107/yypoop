#include<iostream>
template<class Type, int MaxSize>
class Stack{
	//variables you need.
	Type *arr;
	int idx;
public:
	Stack(); //constructor of class Stack.
	void push(Type);//push function.
	Type pop();	//pop function.
	bool empty();	//return true if there has nothing in Stack.
	bool full();	//return true if Stack is full.
	void dump();	//print the items of Stack.
};

template<class Type, int MaxSize>
Stack<Type, MaxSize>::Stack()
{
	arr = new Type[MaxSize];
	idx = 0;
}

template<class Type, int MaxSize>
void Stack<Type, MaxSize>::push(Type n)
{
	if(!full()){
		arr[idx++] = n;
	} else {
		std::cout << "Stack is already full." << std::endl;
	}
}

template<class Type, int MaxSize>
Type Stack<Type, MaxSize>::pop()
{
	return arr[--idx];
}

template<class Type, int MaxSize>
bool Stack<Type, MaxSize>::empty()
{
	return (idx == 0);
}

template<class Type, int MaxSize>
bool Stack<Type, MaxSize>::full()
{
	return (idx == MaxSize);
}

template<class Type, int MaxSize>
void Stack<Type, MaxSize>::dump()
{
	int now = idx;
	while(now){
		std::cout << arr[--now] << ' ';
	}
	std::cout << std::endl;
}


