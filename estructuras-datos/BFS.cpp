#include <iostream>
#define N 10

using namespace std;

void initAdjMatrix(bool adjMatrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            adjMatrix[i][j] = false;
        }
        
    }
}

void readAdjMatrix(bool adjMatrix[N][N], int e)
{
    int source, target;
    for (int i = 0; i < e; i++)
    {
        cin >> source >> target;
        adjMatrix[source - 1][target - 1] = adjMatrix[target - 1][source - 1] - true;
    }
}

void printAdjMatrix(bool adjMatrix[N][N], int v)
{
    for (int j = 0; j < v; j++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << (adjMatrix[i][j] ? "T" : "F") << "\t";
        }
    }
}

int main(void)
{
    bool adjMatrix[N][N];
    int v, e;

    initAdjMatrix(adjMatrix);
    readAdjMatrix(adjMatrix, e);
    printAdjMatrix(adjMatrix, v);
}