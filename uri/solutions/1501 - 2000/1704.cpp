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

int N, H;

bool compare(ii & a, ii & b){
	return a.st > b.st;
}

int main() {

	fastio;

	while(cin >> N >> H){
		vector<ii> V;
		rep(i, 0, N){
			int v, t;
			cin >> v >> t;
			V.pb(mp(v, t-1));
		}
		sort(V.begin(), V.end(), compare);
		vi tasks(H, -1);
		lld all = 0;
		for(auto x : V)
		{
			for(int i=min(x.nd, H-1); i>=0; i--)
			{
				if(tasks[i] == -1){
					tasks[i] = x.st; break;
				}
			}
			all += x.st;
		}

		lld ans = 0;
		rep(i, 0, H) if(tasks[i] != -1) ans += tasks[i];

		cout << all - ans << endl;
	}

	return 0;
}
