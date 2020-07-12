#include <iostream>

using namespace std;

void sumMatrix(int mat[][10])
{
int j;
for (int diag = 0; diag < 10; diag++)
{
    for (int i = 0; i < 10 - diag; i++) 
    {
        j = i + diag;

        if (i == j)
            mat[i][j] = j;
        else
            mat[j][i] = mat[i][j] = mat[i][j - 1] + j;
    }
}

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;        
    }

    
    
}

int main()
{
    int mat[10][10];
    sumMatrix(mat);
    return 0;
}

