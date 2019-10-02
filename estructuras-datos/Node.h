#include <cstddef>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;
public:
    Node(T);
    Node(T, Node<T>*);
    T getData();
    Node<T>* getNext();
    void setData(T);
    void setNext(Node<T>*);
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T>* next)
{
    this->data = data;
    this->next = next;
}

template <class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}