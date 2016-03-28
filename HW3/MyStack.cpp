#include <functional>
#include "MyStack.h"
#include "Coordinate.h"

template<class T>
MyStack<T>::MyStack()
{
    head = NULL;
    size = 0;
}

template<class T>
MyStack<T>::~MyStack()
{
    while(!empty()){
        pop();
    }
}

template<class T>
void MyStack<T>::push(T& value)
{
    head = new Node(value, head);
    ++size;
}

template<class T>
void MyStack<T>::pop()
{
    Node *tmp = head;
    head = head->next;
    delete tmp;
    --size;
}

template<class T>
T& MyStack<T>::top()
{
    return head->value;
}

template<class T>
size_t MyStack<T>::getSize() const
{
    return size;
}

template<class T>
bool MyStack<T>::empty() const
{
    return (size == 0);
}

template<class T>
MyStack<T>::Node::Node(T& value, Node* next)
    : value(value),
    next(next)
{
    
}

template class MyStack<char>;
template class MyStack<Coordinate>;

