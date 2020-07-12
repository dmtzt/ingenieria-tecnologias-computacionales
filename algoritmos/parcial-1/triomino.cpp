#include <iostream>

#define FILLED 1
#define ERROR -1
#define FIRST_QUAD 1
#define SECOND_QUAD 2
#define THIRD_QUAD 3
#define FOURTH_QUAD 4

using namespace std;

void resetArr(int **arr, int n);
void printArr(int **arr, int n);
void triomino(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count);
int locateQuadFilled(int endRow, int endCol, int filledRow, int filledCol);
void firstQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count);
void secondQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count);
void thirdQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count);
void fourthQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count);
void fill1_2_3(int **arr, int filledRow, int filledCol, int &count);
void fill1_2_4(int **arr, int filledRow, int filledCol, int &count);
void fill1_3_4(int **arr, int filledRow, int filledCol, int &count);
void fill2_3_4(int **arr, int filledRow, int filledCol, int &count);


int main(void)
{
    int n, filledRow, filledCol;
    int count = 2;

    cin >> n;

    int **arr = new int *[n];

    for(int i = 0; i <n; i++)
        arr[i] = new int[10];

    resetArr(arr, n);

    cin >> filledRow >> filledCol;

    arr[filledRow][filledCol] = FILLED;

    triomino(arr, 0, n - 1, 0, n - 1, filledRow, filledCol, count);

    cout << endl;

    printArr(arr, n);

    return 0;
}

void resetArr(int **arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
}

void printArr(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];

            if (j + 1 < n)
                cout << '\t';
        }

        cout << endl;
    }        
}

void triomino(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count)
{
    // If a single squared matrix is reached, end recursion
	if (startRow == endRow && startCol == endCol)
        return;
		
	// Locate in which quadrant the filled squared is located
	int location = locateQuadFilled(endRow, endCol, filledRow, filledCol);
	switch (location)
    {
        case FIRST_QUAD:
			firstQuad(arr, startRow, endRow, startCol, endCol, filledRow, filledCol, count);
			break;
		case SECOND_QUAD:
			secondQuad(arr, startRow, endRow, startCol, endCol, filledRow, filledCol, count);
			break;
		case THIRD_QUAD:
			thirdQuad(arr, startRow, endRow, startCol, endCol, filledRow, filledCol, count);
			break;
		case FOURTH_QUAD:
			fourthQuad(arr, startRow, endRow, startCol, endCol, filledRow, filledCol, count);
			break;
    }
}

int locateQuadFilled(int endRow, int endCol, int filledRow, int filledCol)
{
    if (filledRow <= endRow / 2 && filledCol <= endCol / 2)
		return FIRST_QUAD;
	else if (filledRow <= endRow / 2 && filledCol > endCol / 2)
		return SECOND_QUAD;
	else if (filledRow > endRow / 2 && filledCol <= endCol / 2)
		return THIRD_QUAD;
	else if (filledRow > endRow / 2 && filledCol > endCol / 2)
		return FOURTH_QUAD;

	return ERROR;
}
	
void firstQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count)
{
    fill2_3_4(arr, endRow, endCol, count);
    printArr(arr, endRow + 1);
	// Primer cuadrante
	triomino(arr, startRow, endRow / 2, startCol, endCol / 2, filledRow, filledCol, count);
	// Segundo cuadrante
	triomino(arr, startRow, endRow / 2, endCol / 2 + 1, endCol, endRow / 2, endCol / 2 + 1, count);
	// Tercer cuadrante
	triomino(arr, startRow / 2 + 1, endRow, startCol, endCol / 2, endRow / 2 + 1, endCol / 2, count);
	// Cuarto cuadrante
	triomino(arr, endRow / 2 + 1, endRow, endCol / 2 + 1, endCol, endRow / 2 + 1, endCol / 2 + 1, count);
}
	

void secondQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count)
{
    fill1_3_4(arr, endRow, endCol, count);
    printArr(arr, endRow + 1);
	// Primer cuadrante
	triomino(arr, startRow, endRow / 2, startCol, endCol / 2, endRow / 2, endCol / 2, count);
	// Segundo cuadrante
	triomino(arr, startRow, endRow / 2, endCol / 2 + 1, endCol, filledRow, filledCol, count);
	// Tercer cuadrante
	triomino(arr, startRow / 2 + 1, endRow, startCol, endCol / 2, endRow / 2 + 1, endCol / 2, count);
	// Cuarto cuadrante
	triomino(arr, endRow / 2 + 1, endRow, endCol / 2 + 1, endCol, endRow / 2 + 1, endCol / 2 + 1, count);
}
	

void thirdQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count)
{
    fill1_2_4(arr, endRow, endCol, count);
	// Primer cuadrante
	triomino(arr, startRow, endRow / 2, startCol, endCol / 2, endRow / 2, endCol / 2, count);
	// Segundo cuadrante
	triomino(arr, startRow, endRow / 2, endCol / 2 + 1, endCol, endRow / 2, endCol / 2 + 1, count);
	// Tercer cuadrante
	triomino(arr, startRow / 2 + 1, endRow, startCol, endCol / 2, filledRow, filledCol, count);
	// Cuarto cuadrante
	triomino(arr, endRow / 2 + 1, endRow, endCol / 2 + 1, endCol, endRow / 2 + 1, endCol / 2 + 1, count);
}
	

void fourthQuad(int **arr, int startRow, int endRow, int startCol, int endCol, int filledRow, int filledCol, int &count)
{
    fill1_2_3(arr, endRow, endCol, count);
    printArr(arr, endRow + 1);
	// Primer cuadrante
	triomino(arr, startRow, endRow / 2, startCol, endCol / 2, endRow / 2, endCol / 2, count);
	// Segundo cuadrante
	triomino(arr, startRow, endRow / 2, endCol / 2 + 1, endCol, endRow / 2, endCol / 2 + 1, count);
	// Tercer cuadrante
	triomino(arr, startRow / 2 + 1, endRow, startCol, endCol / 2, endRow / 2 + 1, endCol / 2, count);
	// Cuarto cuadrante
	triomino(arr, endRow / 2 + 1, endRow, endCol / 2 + 1, endCol, filledRow, filledCol, count);
}
	

void fill1_2_4(int **arr, int endRow, int endCol, int &count)
{
    // 1
    arr[endRow / 2][endCol / 2] = count;
    // 2
	arr[endRow / 2][endCol / 2 + 1] = count;
    // 4
	arr[endRow / 2 + 1][endCol / 2 + 1] = count;
	count++;
}
	
void fill1_2_3(int **arr, int endRow, int endCol, int &count)
{
    // 1
    arr[endRow / 2][endCol / 2] = count;
	// 2
	arr[endRow / 2][endCol / 2 + 1] = count;
    // 3
	arr[endRow / 2 + 1][endCol / 2] = count;
	count++;
}
	
void fill2_3_4(int **arr, int endRow, int endCol, int &count)
{
    // 2
	arr[endRow / 2][endCol / 2 + 1] = count;
	// 3
	arr[endRow / 2 + 1][endCol / 2] = count;
	// 4
	arr[endRow / 2 + 1][endCol / 2 + 1] = count;
	count++;
}
	
void fill1_3_4(int **arr, int endRow, int endCol, int &count)
{
    // 1
    arr[endRow / 2][endCol / 2] = count;
	// 3
	arr[endRow / 2 + 1][endCol / 2] = count;
	// 4
	arr[endRow / 2 + 1][endCol / 2 + 1] = count;
	count++;
}