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

vector<vi> G(MAX);
vi deg(MAX, oo);

void bfs(int s){
    vector<bool> visited(MAX, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    deg[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]){
            if(!visited[v]){
                deg[v] = deg[u]+1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {

	fastio;
    int n, g;
    cin >> n >> g;
    map<string, int> m;
    map<int, string> mr;
    int idx = 0;
    rep(i, 0, n){
        string a, b;
        cin >> a >> b;
        if(m.find(a) == m.end()){
            m[a] = idx;
            mr[idx] = a;
            idx++;
        }
        if(m.find(b) == m.end()){
            m[b] = idx;
            mr[idx] = b;
            idx++;
        }
        G[m[a]].pb(m[b]);
        G[m[b]].pb(m[a]);
    }

    bfs(m["Rerisson"]);

    vector<string> ans;
    rep(i, 0, idx)if(i != m["Rerisson"]){
        if(deg[i] <= g)
            ans.pb(mr[i]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, 0, ans.size()){
        cout << ans[i] << endl;
    }

	return 0;
}