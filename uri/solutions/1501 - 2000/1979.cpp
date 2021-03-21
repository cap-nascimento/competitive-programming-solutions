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

int n;
bool solve(vector<vector<int>> &G){
	vector<int> side(n+1, -1);
	queue<int> q;	
	for(int st = 1; st <= n; st++){
		if(side[st] == -1){
			q.push(st);
			side[st] = 0;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				for(int u : G[v]){
					if(side[u] == -1){
						side[u] = 1-side[v];
						q.push(u);
					}else{
						if(side[u] == side[v])
							return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {

	fastio;
	while(cin >> n && n){
		vector<vector<int>> G(110);
		rep(i, 0, n){
			int u;
			string v, w;
			cin >> u;
			cin.ignore(1);
			getline(cin, v);
			stringstream iss(v);
			while(iss >> w){
				G[u].pb(stoi(w)); G[stoi(w)].pb(u);
			}
		}
		if(solve(G))
			cout << "SIM\n";
		else
			cout << "NAO\n";
	}

	return 0;
}