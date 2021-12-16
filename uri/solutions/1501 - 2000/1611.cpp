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

	int t;
	cin >> t;
	while(t--){
		int n, c, m;
		cin >> n >> c >> m;
		int a[m];
		rep(i, 0, m) cin >> a[i];
		sort(a, a+m);
		int i = m-1;
		int ans = 0;
		while(i >= 0){
			int tmp = 0;
			ans += (a[i]*2);
			while(tmp < c && i >= 0){
				tmp++;
				i--;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
