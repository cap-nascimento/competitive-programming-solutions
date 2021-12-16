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

int R, K;
vector<vi> G(MAX);

int solve(){
	int dp[K+1] = {0};
	dp[0] = 1;
	rep(i, 1, R+1){
		for(int j=K;j>=(int)G[i].size();j--){
			if(dp[j - G[i].size()] == 1){
				dp[j] = 1;
			}
		}
	}
	return dp[K];
}

int main() {

	fastio;

	while(cin >> R >> K){
		rep(i, 0, MAX) G[i].resize(0);
		rep(i, 0, K){
			int a, b;
			cin >> a >> b;
			G[a].pb(b);
			G[b].pb(a);
		}

		if(solve())
			cout << "S\n";
		else
			cout << "N\n";
	}

	return 0;
}
