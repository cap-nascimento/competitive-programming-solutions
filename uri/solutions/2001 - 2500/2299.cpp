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
#define MAX 1010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int C, F;
int letras[MAX], desculpe[MAX];

int solve(){
	int dp[F+1][C+1];
	for(int i=0;i<=F;i++){
		for(int j=0;j<=C;j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(letras[i-1] <= j)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - letras[i-1]] + desculpe[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[F][C];
}

int main() {

	fastio;
	int t = 1;
	while(cin >> C >> F && !(C == 0 || F == 0)){
		rep(i, 0, F) cin >> letras[i] >> desculpe[i];
		cout << "Teste " << t++ << endl;
		cout << solve() << "\n\n"; 
	}
	return 0;
}
