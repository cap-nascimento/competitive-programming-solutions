/*
    Code to implement various algorithms to use on graphs.
*/
#include <bits/stdc++.h>
#define MAX 1010
#define oo INT_MAX
using namespace std;

/*
****************************************
*   Common classes to the algorithms   *
****************************************
*/

/*
    adj -> adjacency matrix to some algorithms
    G -> the graph (0-indexed)
    n -> number of vertices
    m -> number of edges
*/
class Graph{
    public:
        vector<vector<pair<int, int>>> G;
        int n, m, **adj;
        Graph(int, int);
        void set_edge(int, int, int);
        void dfs();
        void bfs();
};

Graph::Graph(int n, int m){
    // set number of vertices
    this->n = n;
    // set number of edges
    this->m = m;
    // init adjacency list
    this->G.assign(n, vector<pair<int, int>>());
    // init adjacency matrix
    this->adj = new int*[n];
    for(int i=0;i<n;i++){
        this->adj[i] = new int[m];
        for(int j=0;j<m;j++){
            this->adj[i][j] = oo;
        }
    }
}

void Graph::set_edge(int u, int v, int w){
    // set edge on direction u -> v
    this->G[u].push_back(make_pair(v, w));
    // set edge on direction v -> u
    this->G[v].push_back(make_pair(u, w));
    // set edge on adjacency matrix (undirected too)
    this->adj[u][v] = w;
    this->adj[v][u] = w;
}

void Graph::dfs(){
    bool visited[n] = {false};
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        cout << u << " ";
        for(pair<int, int> p : G[u]){
            int v = p.first;
            if(!visited[v]){
                visited[v] = true;
                s.push(v);
            }

        }
    }
}

void Graph::bfs(){
    bool visited[n] = {false};
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(pair<int, int> p : G[u]){
            int v = p.first;
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }

        }
    }
}

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

    return 0;
}