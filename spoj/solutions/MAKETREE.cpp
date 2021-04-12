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
#define MAX 100010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int n, k;
vector<vi> G(MAX);
vi ans;

void topological_sort(){
	vi deg(MAX, 0);
	rep(i, 1, n+1)
		rep(j, 0, G[i].size())
			deg[G[i][j]]++;
	queue<int> q;
	rep(i, 1, n+1)
		if(deg[i] == 0)
			q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.pb(u);
		rep(i, 0, G[u].size()){
			deg[G[u][i]]--;
			if(deg[G[u][i]] == 0)
				q.push(G[u][i]);
		}
	}
}

int main() {

	fastio;

	cin >> n >> k;

	rep(i, 1, k+1){
		int w;
		cin >> w;
		rep(j, 0, w){
			int x;
			cin >> x;
			G[i].pb(x);
		}
	}

	topological_sort();
	vi v(MAX);
	rep(i, 1, n+1){
		v[ans[i-1]] = i-1;
	}

	rep(i, 1, n+1){
		if(v[i]-1 < 0)
			cout << 0;
		else
			cout << ans[v[i]-1];
		cout << endl;
	}

	return 0;
}

