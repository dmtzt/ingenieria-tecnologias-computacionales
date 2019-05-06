#define LIST_SIZE 50

template <class T>
class List
{
    private:
        int size;
        T list[LIST_SIZE];
    public:
        List();
        int getSize();
        void setSize(int);
        bool addElement(T);
        T getByIndex(int);
        int findElement(T);
        void toString();

};

// Es necesario indicar el template en el nombre de la clase
template <class T>
List<T>::List()
{
    size = 0;
}

template <class T>
int List<T>::getSize()
{
    return size;
}

template <class T>
void List<T>::setSize(int size)
{
    this->size = size;
}

template <class T>
bool List<T>::addElement(T element)
{
    if (size == LIST_SIZE)
        return false;

    list[size] = element;
    size++;
    return true;
}

template <class T>
T List<T>::getByIndex(int index)
{
    return list[index];
}

template <class T>
int List<T>::findElement(T element)
{
    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (element == list[i])
            return i;
    }

    return -1;
}

template <class T>
void List<T>::toString()
{
    for (int i = 0; i < LIST_SIZE; i++)
        cout << list[i] << endl;
}