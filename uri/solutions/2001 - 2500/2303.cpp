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
#define lld long long int
#define endl '\n'
using namespace std;

int mtx[MAX][MAX];
int sum[MAX][MAX];

int main(){

	fastio;

	int l, c, m, n;
	cin >> l >> c >> m >> n;

	rep(i, 0, l)
		rep(j, 0, c)
			cin >> mtx[i][j];

	rep(i, 0, l+1){
		rep(j, 0, c+1){
			if(i == 0 || j == 0)
				sum[i][j] = 0;
			else{
				sum[i][j] = mtx[i-1][j-1] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
			}
		}
	}

	int ans = 0;
	rep(i, 0, l){
		if(i+m-1 < l){
			rep(j, 0, c){
				if(j+n-1 < c){
					int s = sum[i+m][j+n] - sum[i][j+n] - sum[i+m][j] + sum[i][j];
					ans = max(ans, s);
					j = j+n-1;
				}
			}
			i = i+m-1;		
		}
	}

	cout << ans << endl;

	return 0;
}