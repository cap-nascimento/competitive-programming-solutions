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
#define MAX 1000002
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int N, M;
vector<vi> G(MAX);

bool solve() {
	queue<ii> q;
	vector<bool> vis(MAX, false);
	vis[1] = true;
	q.push(mp(1, 2));
	while(!q.empty()){
		ii u = q.front();
		// cout << u.st << " " << u.nd << endl;
		if(u.st == M)
			return true;
		q.pop();
		vi g;
		if(u.st - (2*u.nd - 1) > 0)
			g.pb(u.st - (2*u.nd - 1));
		if(u.st + (2*u.nd - 1) <= N)
			g.pb(u.st + (2*u.nd - 1));

		for(auto v : g) {
			// if(!vis[v]){
			// 	vis[v] = true;
				q.push(mp(v, u.nd+1));
			// }
		}
	}
	return false;
}

int main() {

	fastio;
	// rep(i, 1, MAX){
	// 	if((i + (2*i - 1)) < MAX)
	// 		G[i].pb(i + (2*i - 1));
	// 	if(i - (2*i - 1) > 0)
	// 		G[i].pb(i - (2*i - 1));
	// }

	while(cin >> N >> M && (N || M))
	{
		if(N >= 100) cout << "Let me try!" << endl;
		else {
			if(solve()) cout << "Let me try!" << endl;
			else cout << "Don't make fun of me!" << endl;
		}
	}

	return 0;
}