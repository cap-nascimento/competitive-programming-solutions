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

int n, m;
vector<vi> G(MAX);
vector<bool> vis(MAX);
vi ans;

void dfs(int u){
	vis[u] = true;
	for(auto v : G[u]){
		if(!vis[v])
			dfs(v);
	}
	ans.pb(u);
}

void topo(){
	rep(i, 1, n+1) vis[i] = false;
	ans.clear();
	rep(i, 1, n+1){
		if(!vis[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
}

int main() {

	fastio;

	while(cin >> n >> m && (n || m)){
		rep(i, 1, n+1) G[i].resize(0);
		rep(i, 0, m){
			int u, v;
			cin >> u >> v;
			G[u].pb(v);
		}
		topo();
		rep(i, 0, n) cout << ans[i] << (i == n-1 ? "\n" : " ");
	}


	return 0;
}