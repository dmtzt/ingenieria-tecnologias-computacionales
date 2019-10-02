#define PENALTY 20
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Team
{
private:
    map<char, bool> solved;
    int time, score;
    string name;
public:
    int getTime();
    int getScore();
    string getName();
    void setTime(int);
    void setSolved(char, int, bool);
    void setScore(int);
    void setName(string);
    void addTime(int);
    Team();
};

int Team::getTime()
{
    return time;
}

int Team::getScore()
{
    return score;
}

string Team::getName()
{
    return name;
}

void Team::setTime(int time)
{
    this->time = time;
}

void Team::setSolved(char problem, int time, bool judgement)
{
    solved[problem] = judgement;
    addTime(time);

    if (!judgement)
        addTime(PENALTY);
    else
        score++;
}

void Team::setScore(int score)
{
    this->score = score;
}

void Team::setName(string name)
{
    this->name = name;
}

void Team::addTime(int time)
{
    this->time += time;
}

Team::Team()
{
    time = 0;
    score = 0;
}

bool compare(pair<int, Team>&i, pair<int, Team>&j);

int main(void)
{
    string team;
    int num_teams, num_problems, time;
    char problem, accepted;
    bool judgement;
    
    // Map to store all teams
    map<string, Team> teams;

    // Read number of teams and number of problems, and skip endline
    cin >> num_teams >> num_problems;
    cin.ignore();

    // Map to store sorted team
    pair<int, Team> sorted_teams[num_teams];

    // Get every team's name
    for (int i = 0; i < num_teams; i++)
    {
        getline(cin, team);
        teams[team].setName(team);
        teams[team].setScore(0);
    }

    // Read number of problems
    cin >> num_problems;

    // Read problems data
    for (int i = 0; i < num_problems; i++)
    {
        // Read team name, problem, time, and judgement
        cin >> team >> problem >> time >> accepted;

        // Assign corresponding judgement
        if (accepted == 'A')
            judgement = true;
        else if (accepted == 'W')
        {
            judgement = false;
            time = 0;
        }
            

        teams[team].setSolved(problem, time, judgement);
    }

    // Copy map elements to an array to help sorting
    for(map<string, Team>::iterator it = teams.begin(); it != teams.end(); it++)
        sorted_teams[distance(teams.begin(),it)] = make_pair(it->second.getScore(), it->second);

    // Sort array elements by team score in descending order
    sort(sorted_teams, sorted_teams + num_teams, compare);

    // Print formatted results
    for(int i = 0; i < num_teams; i++)
    {
        cout << (i + 1) 
             << " - " 
             << sorted_teams[i].second.getName()
             << " " 
             << sorted_teams[i].second.getScore()
             << " ";

        if(sorted_teams[i].second.getTime() == 0)
            cout << "-";
        else
            cout << sorted_teams[i].second.getTime();

        cout << endl;
    }

    return 0;
}

bool compare(pair<int, Team>&i, pair<int, Team>&j)
{
    if(i.first == j.first)
    {
        if (i.second.getTime() < j.second.getScore())
            return true;
    }
        

    return i.first > j.first;
}