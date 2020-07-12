/*
 * rocky.cpp
 * David Alejandro Martinez Tristan
 * A01610267
 * 
 * Analisis y diseno de algoritmos
 * 13/05/2020
 * 
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int>

vector<int> Dijkstra(Graph& G, int source)
{
    vector<int> Dist;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;

    Dist.assign(G.size(), INF);
    Dist[source] = 0;

    Vertex vx(0, source);
    queue.push(vx);

    while(!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();

        for (int i = 0; i < G[u].size(); i++)
        {
            Edge e = G[u][i];
            int v = e.first;
            int w = e.second;

            if(Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                Vertex vtx(Dist[v], v);
                queue.push(vtx);
            }
        }
    }

    return Dist;
}

int main()
{
    vector<char> results;
    int cases, nodes, edges, u, v, c, longest;
    int source = 1;
    char x, y, room;
    Graph G;

    cin >> cases;

    for (int count = 0; count < cases; count++)
    {
        longest = 0;

        cin >> nodes >> edges;
        G.resize(nodes);

        for (int i = 0; i < edges; i++)
        {
            cin >> x >> y >> c;
            u = x - 'A' + 1;
            v = y - 'A' + 1;

            // Edge from u->v
            Edge edge1(v-1, c);
            G[u-1].push_back(edge1);

            // Edge from v->u
            Edge edge2(u-1, c);
            G[v-1].push_back(edge2);
        }

        vector<int> distances = Dijkstra(G, source-1);

        for (int i = 0; i < nodes; i++)
        {
            if (i != source-1 && distances[i] != INF)
            {
                if (distances[i] > longest)
                {
                    longest = distances[i];
                    room = i + 'A';
                }
            }   
        }

        results.push_back(room);
        G.clear();
    }

    for (int i = 0; i < cases; i++)
        cout << results[i] << endl;

    return 0;
}