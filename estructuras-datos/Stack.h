#include "Node.h"

using namespace std;

template <class T>
class Stack
{
private:
    Node<T>* limit;
    int size;
public:
    void push(T data);
    void pop();
    bool empty();
    int getSize();
    T top();
    Stack(/* args */);
    ~Stack();
};

template <class T>
Stack<T>::Stack()
{
    limit = NULL;
    size = 0;
}

template <class T>
int Stack<T>::getSize()
{
    return size;
}

template <class T>
bool Stack<T>::empty()
{
    return (limit == NULL);
}

template <class T>
T Stack<T>::top()
{
    return limit->getData();
}

template <class T>
void Stack<T>::push(T data)
{
    limit = new Node<T>(data, limit);
    size++;
}

template <class T>
void Stack<T>::pop()
{
    Node<T>* aux = limit;
    limit = limit->getNext();
    delete aux;
    size--;
}

template <class T>
Stack<T>::~Stack(){
    Node<T>* aux = limit;
    while (limit != NULL)
    {
        limit = limit->getNext();
        delete aux;
        aux = limit;
        size--;
    }
}