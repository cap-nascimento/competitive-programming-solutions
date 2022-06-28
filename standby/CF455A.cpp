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
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int a[MAX], dp[MAX];

int solve(int i, map<int, int> c){
	if(i < 0) return 0;
	if(dp[i] == -1){
		int x = 0;
		if(c[a[i]] != 0){
			ii p = {c[a[i]+1], c[a[i]-1]};
			if(c[a[i]+1] != 0) c[a[i]+1] = 0;
			if(c[a[i]-1] != 0) c[a[i]-1] = 0;
			c[a[i]]--;
			x = a[i] + solve(i-1, c);
			c[a[i]]++;
			c[a[i]+1] = p.st;
			c[a[i]-1] = p.nd;
		}
		int y = solve(i-1, c);
		dp[i] = max(x, y);
	}
	return dp[i];
}

int main() {

	fastio;
	int n;
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	map<int, int> c;
	rep(i, 0, n) c[a[i]]++;
	memset(dp, -1, sizeof dp);
	cout << solve(n-1, c) << endl;
	rep(i, 0, n) cout << dp[i] << " ";
	cout << endl;
	return 0;
}
