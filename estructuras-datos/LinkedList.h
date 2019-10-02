#include "Node.h"

template <class T>
class LinkedList {
  public:
    LinkedList();         // Constructor
    LinkedList(LinkedList<T>& list);
    ~LinkedList();        // Destructor

    bool isEmpty();
    int getSize();

    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);

    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();

    T get(int pos);
    T set(int pos, T data);
    Node<T>* getHead();
    bool change(int pos1, int pos2);
    void print();

    void reverse();
    bool operator==(LinkedList<T>& list);
    void operator+=(T data);
    void operator+=(LinkedList<T>& list);
    void shift(int step);

  private:
    Node<T> *head;
    int size;
    void deleteHelper();
};

template <class T>
LinkedList<T>::LinkedList() {
  head = NULL;
  size = 0;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>& list)
{
  Node<T>* temp = list.getHead();

  head->setData(temp->getData());

  for (int i = 1; i < list.getSize(); i++)
  {
    temp = temp->getNext();
    addLast(temp->getData());
  }
}

template <class T>
LinkedList<T>::~LinkedList() {
  deleteHelper();
}

template <class T>
bool LinkedList<T>::isEmpty() {
  return ( head == NULL );
  // return ( size == 0 );
}

template <class T>
int LinkedList<T>::getSize() {
  return size;
}

template <class T>
void LinkedList<T>::addFirst(T data) {
  head = new Node<T>(data, head);
  size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
  if ( this->isEmpty() ) {
    addFirst(data);
  } else {
    Node<T> *curr = head;
    while( curr->getNext() != NULL ) {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data));
    size++;
  }
}

template <class T>
bool LinkedList<T>::add(T data, int pos) {
  if ( pos > size ) {
    return false;
  }
  if ( pos == 0 ) {
    addFirst(data);
  } else if ( pos == size ) {
    addLast(data);
  } else {
    Node<T> *curr = head;
    for( int i = 1; i < pos; i++) {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data, curr->getNext()));
    size++;
  }
  return true;
}

template <class T>
void LinkedList<T>::deleteFirst() {
  if ( !this->isEmpty() ) {
    Node<T> *curr = head;
    head = head->getNext();
    delete curr;
    size--;
  }
}


template <class T>
void LinkedList<T>::deleteLast() {
  if ( size <= 1 ) {
    deleteFirst();
  } else {
    Node<T> *curr = head;
    while( curr->getNext()->getNext() != NULL ) {
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    size--;
  }
}


template <class T>
void LinkedList<T>::del(int pos) {
  if ( pos < size ) {
    if( pos == 0 ) {
      deleteFirst();
    } else if ( pos == size -1 ) {
      deleteLast();
    } else {
      Node<T> *curr = head;
      for( int i = 1; i < pos; i++ ) {
        curr = curr->getNext();
      }
      Node<T> *temp = curr->getNext();
      curr->setNext(temp->getNext());
      delete temp;
      size--;
    }
  }
}


template <class T>
int LinkedList<T>::deleteAll() {
  int cant = size;
  deleteHelper();
  size = 0;
  return cant;
}

template <class T>
void LinkedList<T>::deleteHelper() {
  Node<T> *curr = head;
  while( !this->isEmpty() ) {
    head = head->getNext();
    delete curr;
    curr = head;
  }
}


template <class T>
T LinkedList<T>::get(int pos) {
  Node<T> *curr = head;
  for( int i = 0; i < pos; i++ ) {
    curr = curr->getNext();
  }
  return curr->getData();
}


template <class T>
T LinkedList<T>::set(int pos, T data) {
  Node<T> *curr = head;
  for( int i = 0; i < pos; i++ ) {
    curr = curr->getNext();
  }
  T temp = curr->getData();
  curr->setData(data);
  return temp;
}

template <class T>
Node<T>* LinkedList<T>::getHead()
{
  return head;
}


template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
  if ( pos1 == pos2 ) {
    return true;
  }

  int posMen = ( pos1 < pos2 ? pos1 : pos2 );
  int posMay = ( pos1 > pos2 ? pos1 : pos2 );

  Node<T> *curr = head;
  for( int i = 0; i < posMen; i++ ) {
    curr = curr->getNext();
  }

  Node<T> *curr2 = curr;
  for( int i = posMen; i < posMay; i++ ) {
    curr2 = curr2->getNext();
  }

  T temp = curr->getData();
  curr->setData(curr2->getData());
  curr2->setData(temp);

  return true;
}


template <class T>
void LinkedList<T>::print() {
  Node<T> *curr = head;
  while( curr != NULL ) {
    cout << curr->getData() << " ";
    curr = curr->getNext();
  }
  cout << endl;
}

template <class T>
void LinkedList<T>::reverse()
{
  if (size > 1)
  {
    Node<T>* prev = NULL;
    Node<T>* curr = head;
    Node<T>* next = next->getNext();

    for (int i = 0; i < size; i++)
    {
      curr->setNext(prev);
      prev = curr;
      curr = next;
      next = next->getNext();
    }
  }
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T>& list)
{
  if (size != list.getSize())
    return false;

  Node<T>* temp1 = head;
  Node<T>* temp2 = list.getHead();

  for (int i = 0; i < size; i++)
  {
    if (temp1->getData() != temp2->getData())
      return false;

    temp1 = temp1->getNext();
    temp2 = temp2->getNext();
  }

  return true;
}

template <class T>
void LinkedList<T>::operator+=(T data)
{
  addLast(data);
}

template <class T>
void LinkedList<T>::operator+=(LinkedList<T>& list)
{
  Node<T>* temp = list.getHead();

  for (int i = 0; i < list.getSize(); i++)
  {
    addLast(temp->getData());
    temp = temp->getNext();
  } 
}

template <class T>
void LinkedList<T>::shift(int steps)
{
  Node<T>* prev;
  Node<T>* temp;
  Node<T>* start = head;

  steps %= size;

  if(steps > 0)
    steps = size - steps + 1;
  else
    steps = -steps;

  for (int i = 0; i < steps; i++)
  {
    prev = head;
    head = head->getNext();
  }

  prev->setNext(NULL);

  temp = head;

  while(temp->getNext()!= NULL)
    temp = temp->getNext();

  temp->setNext(start);  
}