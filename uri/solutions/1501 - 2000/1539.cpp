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
#define MAX 110
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

vector<vector<pair<int, double>>> G(MAX);
int n, c;

double eucli(int x1, int x2, int y1, int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

string dijkstra(int s, int d){
	double dist[MAX];
	priority_queue<pair<int, double>, vector<pair<int, double>>, 
					greater<pair<int, double>>> pq;
	rep(i, 0, n) dist[i] = oo;
	dist[s] = 0;

	pq.push(mp(s, 0));

	while(!pq.empty()){
		int u = (pq.top()).st;
		double w = (pq.top()).nd;

		pq.pop();

		if(w > dist[u])
			continue;

		for(auto x : G[u]){
			int v = x.st;
			w = x.nd;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u]+w;
				pq.push(mp(v, dist[v]));
			}
		}
	}

	if(dist[d] == oo)
		return "-1";

	string k = to_string(dist[d]);
	return k.substr(0, (k.find('.')));
}

int main() {

	fastio;

	while(cin >> n && n){
		vector<ii> pts;
		vi rad;
		rep(i, 0, n){
			int x, y, r;
			cin >> x >> y >> r;
			pts.pb(mp(x, y));
			rad.pb(r);
		}
		rep(i, 0, n){
			rep(j, 0, n) if(i != j){
				double d = eucli(pts[i].st, pts[j].st, pts[i].nd, pts[j].nd);
				if(d <= rad[i]){
					G[i].pb(mp(j, d));
				}
			}
		}
		cin >> c;
		rep(i, 0, c){
			int s, d;
			cin >> s >> d;
			cout << dijkstra(s-1, d-1) << endl;
		}
		rep(i, 0, n) G[i].resize(0);
	}

	return 0;
}