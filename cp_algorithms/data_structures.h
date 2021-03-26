#ifndef DATA_STRUCTURES_H_INCLUDED
#define DATA_STRUCTURES_H_INCLUDED

#include <bits/stdc++.h>
#define MAX 1010
#define oo INT_MAX
using namespace std;

/*
    Code to implement segment tree (sum queries)
    Source: https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-3
*/

class SegTree {
private:
    vector<int> st;
    vector<int> a;
    int N;
public:
    SegTree(int _n, vector<int> _a){
        N = _n;
        a = _a;
        st.assign(4*N, 0);
    }

    void build(int tl, int tr, int v){
        if(tl == tr)
            st[v] = a[tl];
        else{
            int tm = (tr-tl)/2 + tl;
            build(tl, tm, v*2);
            build(tm+1, tr, v*2+1);
            st[v] = st[v*2] + st[v*2+1];
        }
    }

    int st_sum(int tl, int tr, int l, int r, int v) {
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return st[v];
        int tm = (tr-tl)/2 + tl;
        return st_sum(tl, tm, l, min(r, tm), v*2) + 
            st_sum(tm+1, tr, max(l, tm+1), r, v*2+1);
    }

};

/*
    Code to implement DSU (Disjoint set union)
    Source: https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
*/

class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int v){
        parent.assign(v+1, 0);
        rank.assign(v+1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
};

/*
**********************************************
*   Common classes to the graph algorithms   *
**********************************************
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

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp_min(Edge &a, Edge &b){
    return a.w < b.w;
}
bool cmp_max(Edge &a, Edge &b){
    return a.w > b.w;
}

#endif // DATA_STRUCTURES_H_INCLUDED