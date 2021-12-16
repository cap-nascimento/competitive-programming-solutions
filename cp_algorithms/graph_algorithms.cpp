/*
    Code to implement various algorithms to use on graphs.
*/
#include "data_structures.h"

/*
****************************************
*             Algorithms               *
****************************************
*/

/*
    Dijkstra's Shortest Path

    s -> source
    d -> destiny

    returns : -1 if the path doesn't exists. The weigth otherwise
*/
int shortest_path(int s, int d, Graph graph){
    int dist[graph.n];
    for(int i=0;i<graph.n;i++) dist[i] = INT_MAX;
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push(make_pair(s, 0));
    while(!queue.empty()){
        pair<int, int> p = queue.top();
        queue.pop();
        int u = p.first;
        int w = p.second;
        if(w > dist[u])
            continue;
        for(pair<int, int> p : graph.G[u]){
            int v = p.first;
            int w = p.second;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                queue.push(make_pair(v, dist[v]));
            }
        }
    }
    return dist[d] == INT_MAX ? -1 : dist[d];
}

/*
    All Pair Shortest Path Floyd-Warshall

    Runs on an adjacency matrix
*/

void floyd_warshall(Graph graph){
    for(int k=0;k<graph.n;k++){
        for(int i=0;i<graph.n;i++){
            for(int j=0;j<graph.n;j++){
                if(graph.adj[i][k] < oo &&
                    graph.adj[k][j] < oo){
                    graph.adj[i][j] = min(graph.adj[i][j], graph.adj[i][k]+graph.adj[k][j]);
                }
            }
        }
    }
}

/*

    Kruskal Minimum Spanning Tree
    
    edges -> array representing graph (just edges)
    n -> vertices

*/

int kruskal(vector<Edge> edges, int n){
    int cost = 0;
    DSU dsu(n);
    sort(edges.begin(), edges.end(), cmp_max);
    for(Edge e: edges){
        if(dsu.find_set(e.u) != dsu.find_set(e.v)){
            cost += e.w;
            dsu.union_sets(e.u, e.v);
        }
    }
    return cost;
}

int main(){

    Graph graph(9, 10);

    graph.set_edge(0, 8, 4);
    graph.set_edge(0, 3, 2);
    graph.set_edge(0, 1, 3);
    graph.set_edge(8, 4, 8);
    graph.set_edge(3, 4, 1);
    graph.set_edge(3, 2, 6);
    graph.set_edge(2, 5, 1);
    graph.set_edge(2, 7, 2);
    graph.set_edge(1, 7, 4);
    graph.set_edge(5, 6, 8);

    //graph.dfs();
    //graph.bfs();

    // Dijkstra example
    cout << "Shortest path using Dijkstra's (" << 2 << "->" << 8 << "): ";
    cout << shortest_path(2, 8, graph) << endl;

    // Floyd-Warshall example
    cout << "Shortest path using Floyd-Warshall's (" << 2 << "->" << 8 << "): ";
    floyd_warshall(graph);
    cout << graph.adj[2][8] << endl;

    // Kruskal Example
    vector<Edge> edges = {
        Edge(1, 2, 96),
        Edge(1, 3, 9),
        Edge(2, 3, 79)
    };

    cout << kruskal(edges, 3) << endl;

    return 0;
}
