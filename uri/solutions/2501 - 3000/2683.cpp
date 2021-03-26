/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define vi vector<int>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define MAX 1000010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

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

void kruskal(vector<Edge> &edges, int n){
    int cost = 0;
    DSU dsu(n);
    sort(edges.begin(), edges.end(), cmp_max);
    for(Edge e: edges){
        if(dsu.find_set(e.u) != dsu.find_set(e.v)){
            cost += e.w;
            dsu.union_sets(e.u, e.v);
        }
    }
    cout << cost << endl;
    cost = 0;
    DSU dsu1(n);
    sort(edges.begin(), edges.end(), cmp_min);
    for(Edge e: edges){
        if(dsu1.find_set(e.u) != dsu1.find_set(e.v)){
            cost += e.w;
            dsu1.union_sets(e.u, e.v);
        }
    }
    cout << cost << endl;
}

int main() {

	fastio;
	int n;
	cin >> n;
	vector<Edge> edges;

	rep(i, 0, n){
		int u, v, w;
		cin >> u >> v >> w;
		edges.pb(Edge(u, v, w));
	}

	kruskal(edges, n);

	return 0;
}