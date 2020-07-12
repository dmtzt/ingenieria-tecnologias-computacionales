#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int>  // Distance from source, vertex ID

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
        int u = queue.top().second;  // Vertex ID
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
    int nodes, edges, source, u, v, w;
    Graph G;

    // Read from stdin
    cin >> nodes >> edges >> source;
    G.resize(nodes);

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;

        // Edge from u->v
        Edge edge1(v-1, w);
        G[u-1].push_back(edge1);

        // Edge from v->u
        Edge edge2(u-1, w);
        G[v-1].push_back(edge2);
    }

    // We run our algorithm
    vector<int> distances = Dijkstra(G, source-1);

    cout << "Minumum distances: " << endl;
    for (int i = 0; i < nodes; i++)
    {
        if (i != source-1)
        {
            cout << source << " -> " << i+1 << " : ";
            if (distances[i] == INF)
            {
                cout << "INFINITY" << endl;
            }
            else
            {
                cout << distances[i] << endl;
            }
        }
    }

    return 0;
}