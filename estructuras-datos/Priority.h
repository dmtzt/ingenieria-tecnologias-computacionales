/*
 * Priority.h
 * Implementation of a priority queue using a heap
 * David Alejandro Martinez Tristan
 * A01610267
*/
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
    void print();
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
}

void Priority::pop()
{
    unsigned int pos = 1;

    int temp = heap[heap.size() - 1];
    heap[heap.size() - 1] = heap[1];
    heap[1] = temp;

    heap.pop_back();

    while (pos < heap.size())
    {   
        if (pos * 2 + 1 < heap.size())
        {
            if (priority)
            {
                if (heap[pos * 2] > heap[pos] && heap[pos * 2] > heap[pos * 2 + 1])
                {
                    temp = heap[pos * 2];
                    heap[pos * 2] = heap[pos];
                    heap[pos] = temp;
                    pos *= 2;
                }
                else if (heap[pos * 2 + 1] > heap[pos] && heap[pos * 2 + 1] > heap[pos * 2])
                {
                    temp = heap[pos * 2 + 1];
                    heap[pos * 2 + 1] = heap[pos];
                    heap[pos] = temp;
                    pos = pos * 2 + 1;
                }
                else
                    return;
            }
            else
            {
                if (heap[pos * 2] < heap[pos] && heap[pos * 2] < heap[pos * 2 + 1])
                {
                    temp = heap[pos * 2];
                    heap[pos * 2] = heap[pos];
                    heap[pos] = temp;
                    pos *= 2;
                }
                else if (heap[pos * 2 + 1] < heap[pos] && heap[pos * 2 + 1] < heap[pos * 2])
                {
                    temp = heap[pos * 2 + 1];
                    heap[pos * 2 + 1] = heap[pos];
                    heap[pos] = temp;
                    pos = pos * 2 + 1;
                }
                else
                    return;
            }
        }
        else if (pos * 2 < heap.size())
        {
            if (priority)
            {
                if (heap[pos * 2] > heap[pos])
                {
                    temp = heap[pos * 2];
                    heap[pos * 2] = heap[pos];
                    heap[pos] = temp;
                    pos *= 2;
                }
                else
                    return;
            }
            else
            {
                if (heap[pos * 2] < heap[pos])
                {
                    temp = heap[pos * 2];
                    heap[pos * 2] = heap[pos];
                    heap[pos] = temp;
                    pos *= 2;
                }
                else
                    return;
            }
        }
        else
            return;
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

void Priority::print()
{
    for (unsigned int i = 1; i < heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}