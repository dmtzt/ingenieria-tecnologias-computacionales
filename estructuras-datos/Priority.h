#include <vector>
#include <iostream>
using namespace std;

class Priority
{
private:
    vector<int> heap;
    bool priority;
public:
    Priority();
    Priority(bool);
    void push(int);
    void pop();
    int top();
    int size();
    bool empty();
};

Priority::Priority()
{
    priority = true;
    heap.push_back(-1);
}

Priority::Priority(bool priority)
{
    this->priority = priority;
    heap.push_back(-1);
}

void Priority::push(int data)
{
    heap.push_back(data);
    int pos = heap.size() - 1;
    int temp;

    while (pos > 1)
    {
        if (priority)
        {
            if (data > heap[pos / 2])
            {
                temp = heap[pos];
                heap[pos] = heap[pos / 2];
                heap[pos / 2] = temp;
            }
            else
                return;
        }
        else
        {
            if (data < heap[pos / 2])
            {
                temp = heap[pos];
                heap[pos] = heap[pos / 2];
                heap[pos / 2] = temp;
            }
            else
                return;
        }

        pos /= 2;
    }
    cout << "Element added" << " " << heap.size() << endl;
}

void Priority::pop()
{
    unsigned int pos = 1;

    for (unsigned int i = 1; i < heap.size(); i++)
            cout << heap[i] << " ";  
        cout << endl;  

    int temp = heap[heap.size() - 1];
    heap[heap.size() - 1] = heap[1];
    heap[1] = temp;

    heap.pop_back();

    while (pos < heap.size())
    {
        if (priority)
        {
            if (heap[pos * 2] > heap[pos * 2 + 1])
            {
                temp = heap[pos * 2];
                heap[pos * 2] = heap[pos];
                heap[pos] = temp;
                pos *= 2;
            }
            else
            {
                temp = heap[pos * 2 + 1];
                heap[pos * 2 + 1] = heap[pos];
                heap[pos] = temp;
                pos = pos * 2 + 1;
            }
        }
        else
        {
            if (heap[pos * 2] < heap[pos * 2 + 1])
            {
                temp = heap[pos * 2];
                heap[pos * 2] = heap[pos];
                heap[pos] = temp;
                pos *= 2;
            }
            else
            {
                temp = heap[pos * 2 + 1];
                heap[pos * 2 + 1] = heap[pos];
                heap[pos] = temp;
                pos = pos * 2 + 1;
            }
        }
    }
}

int Priority::top()
{
    return heap[1];
}

int Priority::size()
{
    return heap.size() - 1;
}

bool Priority::empty()
{
    return (heap.size() == 1) ? true : false;
}