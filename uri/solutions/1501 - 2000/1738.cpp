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
#define MAX 210
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int n;
int d[MAX][MAX];
int ans[MAX][MAX][26];
vector<vector<vector<int>>> adj(MAX);

void put(int i, int k, int j){
    if(i != k)
        rep(l, 0, adj[i][k].size()) ans[i][k][adj[i][k][l]] = 1;
    if(k != j)
        rep(l, 0, adj[k][j].size()) ans[k][j][adj[k][j][l]] = 1;
    if(i != k && k != j)
        rep(l, 0, 26) ans[i][j][l] = ans[i][j][l] | (ans[i][k][l] & ans[k][j][l]);
}

void fw(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k] < oo && d[k][j] < oo){
                    put(i, k, j);
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
}

int main() {

	fastio;
    while(cin >> n && n){
        int a, b;
        rep(i, 0, n){
            adj[i] = vector<vector<int>>(MAX);
        	rep(j, 0, n){
        		d[i][j] = (i == j ? 0 : oo);
                rep(k, 0, 26)
                    ans[i][j][k] = 0;
        	}
        }
        while(cin >> a >> b && (a || b)){
            d[a-1][b-1] = 1;
            adj[a-1][b-1] = {};
            string c;
            cin >> c;
            rep(i, 0, c.size()){
            	adj[a-1][b-1].pb(c[i]-'a');
                ans[a-1][b-1][c[i]-'a'] = 1;
            }
        }

        fw();

        while(cin >> a >> b && (a || b)){
            a--; b--;
            string s = "";
            rep(i, 0, 26){
                if(ans[a][b][i]) s += (char)(i+'a');
            }
            cout << (s.size() == 0 ? "-" : s) << endl;
        }
        cout << endl;
    }

	return 0;
}