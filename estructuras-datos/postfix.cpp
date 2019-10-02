#include <cctype>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool isOperator(string value);

int main(void)
{
    queue<int> queue;
    stack<int> stack;
    priority_queue<int, vector<int>, greater<int>> priorityQueue;
    vector<int> outQueue;
    vector<int> outStack;
    vector<int> outPriorityStack;
    string data, word;
    int value;
    int xQueue, xStack, xPriorityQueue;
    int yQueue, yStack, yPriorityQueue;
    int resQueue, resStack, resPriorityQueue;

    do
    {   
        getline(cin, data);
        stringstream ss;
        ss << data;

        if (data != "#")
        {
            while (ss >> word && data != "#")
            {
                if (isOperator(word))
                {
                    xQueue = queue.front();
                    xStack = stack.top();
                    xPriorityQueue = priorityQueue.top();
                    
                    queue.pop();
                    stack.pop();
                    priorityQueue.pop();

                    yQueue = queue.front();
                    yStack = stack.top();
                    yPriorityQueue = priorityQueue.top();
                    
                    queue.pop();
                    stack.pop();
                    priorityQueue.pop();
                        
                    if (word == "+")
                    {
                        resQueue = yQueue + xQueue;
                        resStack = yStack + xStack;
                        resPriorityQueue = yPriorityQueue + xPriorityQueue;
                    }
                    else if (word == "-")
                    {
                        resQueue = yQueue - xQueue;
                        resStack = yStack - xStack;
                        resPriorityQueue = yPriorityQueue - xPriorityQueue;
                    }
                    else if (word == "*")
                    {
                        resQueue = yQueue * xQueue;
                        resStack = yStack * xStack;
                        resPriorityQueue = yPriorityQueue * xPriorityQueue;
                    }
                    
                    queue.push(resQueue);
                    stack.push(resStack);
                    priorityQueue.push(resPriorityQueue);
                }
                else
                {
                    value = stoi(word);

                    queue.push(value);
                    stack.push(value);
                    priorityQueue.push(value);
                }
            }

            stack.pop();
            queue.pop();
            priorityQueue.pop();

            outStack.push_back(resStack);
            outQueue.push_back(resQueue);
            outPriorityStack.push_back(resPriorityQueue);
        }
    } while (data != "#");

    for (unsigned int i = 0; i < outStack.size(); i++)
    {
        cout  << outStack[i] 
              << " " 
              << outQueue[i] 
              <<  " " 
              << outPriorityStack[i] 
              << endl;
    }
    return 0;
}

bool isOperator(string word)
{
    if (word == "+" || word == "-" || word == "*")
        return true;
    
    return false;
}