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
#define MAX 10010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;

	int n;
	while(cin >> n){
		vector<ii> v;
		rep(i, 0, n){
			int d, p;
			cin >> d >> p;
			v.pb({d, p});
		}
		sort(v.begin(), v.end());
		int ans = 1;
		rep(i, 0, n){
			if(ans < v[i].st)
				ans += (v[i].st - ans);
			ans += v[i].nd;
		}
		cout << ans << endl;
	}

	return 0;
}
