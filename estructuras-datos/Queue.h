#include "Node.h"

using namespace std;

template <class T>
class Queue
{
private:
    int size;
    Node<T>* end;
public:
    Queue();
    ~Queue();

    void push(T);
    void pop();
    T front();
    int getSize();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue()
{
    end = NULL;
    size = 0;
}

template <class T>
Queue<T>::~Queue()
{
    if (end != NULL)
    {
        Node<T>* aux = end->getNext();
        end->setNext(NULL);
        end = aux;

        while (end != NULL)
        {
            end = end->getNext();
            delete aux;
            aux = end;
        }

        size = 0;
    }
}

template <class T>
void Queue<T>::push(T data)
{
    if (end == NULL)
    {
        end = new Node<T>(data);
        end->setNext(end);
    }
    else
    {
        end->setNext(new Node<T>(data, end->getNext()));
        end = end->getNext();
    }
    
    size++;
}

template <class T>
void Queue<T>::pop()
{
    Node<T>* aux = end->getNext();
    if (aux == end)
        end = NULL;
    else
        end->setNext(aux->getNext());
    delete aux;
    size--;
}

template <class T>
T Queue<T>::front()
{
    return end->getNext()->getData();
}

template <class T>
int Queue<T>::getSize()
{
    return size;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (end == NULL);
}