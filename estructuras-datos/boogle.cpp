#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void resetStatus(bool* status);
int calculateScore(string word);
void calculateAdjacencies(vector< vector<int> >& adjList);
bool findWord(string word, int& index, int number, char* board, vector<bool>& status, vector< vector<int> >& adjList);

int main(void)
{
    int n, m;
    int score = 0;
    int index = 1;
    char letter;
    string word;
    char board[16];
    vector< vector<int> > adjList(16);
    vector<bool> status(16, false);
    bool adjMatrix;

    cin >> n;

    for (int i = 0; i < 16; i++)
    {
        cin >> letter;
        board[i] = letter;
    }

    // Adjacencies are stored
    calculateAdjacencies(adjList);

    cin >> word;

    for (int i = 0; i < 16; i++)
    {
        if (word[0] == board[i])
        {
            cout << "Start" << endl;
            if (findWord(word, index, i, board, status, adjList))
            {
                cout << "Found!" << endl;
                break;
            }
        }   
    }

    cout << "Not found" << endl;
    
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        score = 0;

        for (int j = 0; j < m; j++)
        {
            index = 0;
            cin >> word;

            for (int i = 0; i < 16; i++)
            {
                if (word[0] == board[i])
                {
                    if (findWord(word, index, i, board, status, adjList))
                    {
                        score += calculateScore(word);
                        break;
                    }
                }   
            }
        }
        
        cout << score << endl;   
    }
    
    return 0;
}

void resetStatus(bool* status)
{
    for (int i = 0; i < 16; i++)
        status[i] = false;
}

int calculateScore(string word)
{
    int size = word.size();

    switch (size)
    {
    case 3:
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 3;
    case 7:
        return 5;
    case 8:
    default:
        return 11;
    }
}

void calculateAdjacencies(vector< vector<int> >& adjList)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Horizontal adjacencies
            adjList[i * 4 + j].push_back(i * 4 + j + 1);
            adjList[i * 4 + j + 1].push_back(i * 4 + j);
            // Vertical adjacencies
            adjList[i + j * 4].push_back(i + j * 4 + 4);
            adjList[i + j * 4 + 4].push_back(i + j * 4);
            
            // Largest diagonal adjacencies
            if (i == 0)
            {
                adjList[j * 5].push_back(j * 5 + 5);
                adjList[j * 5 + 5].push_back(j * 5);
                adjList[(j + 1) * 3].push_back((j + 1) * 3 + 3);
                adjList[(j + 1) * 3 + 3].push_back((j + 1) * 3);
            }
        }
    }

    adjList[1].push_back(4);
    adjList[4].push_back(1);
    adjList[2].push_back(5);
    adjList[5].push_back(2);
    adjList[5].push_back(8);
    adjList[8].push_back(5);

    adjList[7].push_back(10);
    adjList[10].push_back(7);
    adjList[10].push_back(13);
    adjList[13].push_back(10);
    adjList[11].push_back(14);
    adjList[11].push_back(14);

    adjList[1].push_back(6);
    adjList[6].push_back(1);
    adjList[11].push_back(6);
    adjList[6].push_back(11);
    adjList[2].push_back(7);
    adjList[7].push_back(2);

    adjList[4].push_back(9);
    adjList[9].push_back(4);
    adjList[9].push_back(14);
    adjList[14].push_back(9);
    adjList[8].push_back(13);
    adjList[13].push_back(8);

    for (int i = 0; i < 16; i++)
        sort(adjList[i].begin(), adjList[i].end());
    
}

bool findWord(string word, int& index, int number, char* board, vector<bool>& status, vector< vector<int> >& adjList)
{
    //cout << "Adjacency list of " << number << endl;
    //cout << "Word letter: " << word[index] << endl;

    for (int i = 0; i < adjList[number].size(); i++)
    {
        //cout << "Board letter: " << board[adjList[number][i]] << " " << adjList[number][i] << endl;

        if (word[index] == board[adjList[number][i]] && !status[adjList[number][i]])
        {
            //cout << "Here: " << board[adjList[number][i]] << " " << adjList[number][i] << endl;

            if (index == word.length() - 1)
                return true;
            else if (findWord(word, ++index, adjList[number][i], board, status, adjList))
                return true;
        }
    }

    return false;
}