/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <iostream>
#include <vector>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define vi vector<int>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define MAX 1010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;		

	int n, q;
	map<int, vi> emp;

	cin >> n;
	int d[n+1];
	rep(i, 0, n){
		emp[i+1] = vi();
		d[i+1] = i+1;
	}
	cin >> q;
	while(q--) {
		int e;
		cin >> e;
		if(e == 1) {
			int a, b;
			cin >> a >> b;
			d[a] = (emp[b].size() == 0 ? b : emp[b][emp[b].size()-1]);
			d[b] = (emp[a].size() == 0 ? a : emp[a][emp[a].size()-1]);
			emp[a].pb(d[a]);
			emp[b].pb(d[b]);
		} else {
			int a;
			cin >> a;
			int ans = 0, x = d[a];
			while(x != a){
				vi v = emp[x];
				x = v[v.size()-1];
				ans++;
			}
			cout << ans << endl;
		}
	}

	return 0;
}
