#define PENALTY 20
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

/*
 * TODO
 * 
 * Ordenar por puntaje de forma ascendente
 * Si dos o más equipos tienen el mismo puntaje, ordenar por tiempo
*/


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