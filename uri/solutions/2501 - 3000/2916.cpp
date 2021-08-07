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

lld v[MAX];

int main() {

	fastio;

	int n, k;
	while(cin >> n >> k)
	{
		rep(i, 0, n) cin >> v[i];
		sort(v, v+n);
		lld ans = 0;
		for(int i=n-1;i>=(n-k);i--) ans = (ans + v[i])%MOD;
		cout << ans << endl;
	}

	return 0;
}
