//
// Matricula:
// Nombre:
//
//

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

/*
El mÃ©todo ordenaxPotencia debera ordena por potencia en forma descendente y generar un nuevo vector
que regresarÃ¡ de salida listo para ser impreso.
*/

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) 
{ 
    if (a.second == b.second)
        return true;
    return (a.second > b.second); 
}

vector<string> ordenaxPotencia(vector<string> &v){
    int O = 0;
    int H = 1;

    int potential[v.size()][2];
    map<int, int> total;

    for (int i = 0; i < v.size(); i++)
    {
        potential[i][O] = 0;
        potential[i][H] = 0;
        
        for (int j = 0; j < v[i].length(); j++)
        {
            if (v[i][j] == 'O')
                potential[i][O]++;
            else if (v[i][j] == 'H')
                potential[i][H]++;
        }

        total[i] = min(potential[i][O], potential[i][H]);
    }

	vector<pair<int, int>> aux;

    map<int, int> :: iterator it;
    for (it =total.begin(); it != total.end(); it++) 
    {
        aux.push_back(make_pair(it->first, it->second));
    }

    sort(aux.begin(), aux.end(), sortByVal);
    
    vector<string> res;
    for (int i = 0; i < v.size(); i++)
        res.push_back(v[aux[i].first]);
    
    return res;
}


int main() {
    
    int l, n;
    string adn;
    vector<string> v;
    cin >> l >> n;
    for(int i = 0; i < n; i++){
        cin >> adn;
        v.push_back(adn);
    }
    vector<string> sale = ordenaxPotencia(v);
    for(int i = 0; i < n; i++){
        cout << sale[i]<<  endl;
    }
    return 0;
}