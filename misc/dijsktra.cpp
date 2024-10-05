#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair
#include <limits>  // for std::numeric_limits

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Dijkstra's algorithm function
void dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size(); // Number of nodes in the graph

    // Distance vector to store the shortest distance from the start node
    vector<int> distance(n, INF);
    distance[start] = 0;

    // Priority queue to process nodes (min-heap), stores pairs {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start}); // Distance to start node is 0

    while (!pq.empty()) {
        int dist = pq.top().first;  // Current distance
        int node = pq.top().second; // Current node
        pq.pop();

        // If this distance is already greater than the stored distance, skip
        if (dist > distance[node]) continue;

        // Explore neighbors
        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path to nextNode is found
            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    // Print the shortest distances from the start node
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF)
            cout << "Node " << i << ": INF (unreachable)\n";
        else
            cout << "Node " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    // Number of nodes (0-indexed graph)
    int n = 5;

    // Graph represented as an adjacency list
    // graph[node] = vector of {neighbor, weight}
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges to the graph
    // Example graph (directed, weighted edges):
    graph[0].push_back({1, 10}); // Edge from 0 to 1 with weight 10
    graph[0].push_back({4, 5});  // Edge from 0 to 4 with weight 5
    graph[1].push_back({2, 1});  // Edge from 1 to 2 with weight 1
    graph[1].push_back({4, 2});  // Edge from 1 to 4 with weight 2
    graph[2].push_back({3, 4});  // Edge from 2 to 3 with weight 4
    graph[3].push_back({0, 7});  // Edge from 3 to 0 with weight 7
    graph[3].push_back({2, 6});  // Edge from 3 to 2 with weight 6
    graph[4].push_back({1, 3});  // Edge from 4 to 1 with weight 3
    graph[4].push_back({2, 9});  // Edge from 4 to 2 with weight 9
    graph[4].push_back({3, 2});  // Edge from 4 to 3 with weight 2

    int startNode = 0; // Starting node for Dijkstra's algorithm

    // Run Dijkstra's algorithm from the start node
    dijkstra(startNode, graph);

    return 0;
}
