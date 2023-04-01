// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000000LL

// iPair ==> Integer Pair
typedef pair<long long int, long long int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    long long int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge 100010
    vector<pair<long long int, long long int>> adj[100010];

public:
    Graph(long long int V); // Constructor

    // function to add an edge to graph
    void addEdge(long long int u, long long int v, long long int w);

    // prints shortest path from s
    void shortestPath(long long int s);
};

// Allocates memory for adjacency list
Graph::Graph(long long int v)
{
    V = v;
}

void Graph::addEdge(long long int u, long long int v, long long int w)
{
    adj[u].push_back(make_pair(v, w));
    // adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(long long int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<long long int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty())
    {

        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        long long int u = pq.top().second;
        if (pq.top().first > dist[u])
        {
            pq.pop();
            continue;
        }
        pq.pop();

        // 'i' is used to get all adjacent vertices of a
        // vertex
        vector<pair<long long int, long long int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current
            // adjacent of u.
            long long int v = (*i).first;
            long long int weight = (*i).second;

            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    // printf("Vertex Distance from Source\n");
    // for (int i = 0; i < V; ++i)
    //     printf("%d \t\t %d\n", i, dist[i]);
    for (long long int i = 0; i < V; ++i)
        cout << dist[i] << " ";
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above figure
    // int V = 9;

    long long int m, n, inicio, fin, costo;

    cin >> n >> m;

    // int V = 3;

    Graph g(n);

    while (m)
    {
        cin >> inicio >> fin >> costo;
        g.addEdge(inicio - 1, fin - 1, costo);
        m--;
    }

    // g.addEdge(0, 1, 6);
    // g.addEdge(0, 2, 2);
    // g.addEdge(2, 1, 3);
    // g.addEdge(0, 2, 4);

    g.shortestPath(0);

    return 0;
}