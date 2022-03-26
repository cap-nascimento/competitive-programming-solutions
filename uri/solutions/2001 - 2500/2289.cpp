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

int main() {

	fastio;

	lld x, y;
	while(cin >> x >> y && (x || y)){
		int a[64] = {0};
		int b[64] = {0};
		int i = 0;
		while(x > 0 || y > 0){
			a[i] = x%2; x/=2;
			b[i] = y%2; y/=2;
			i++;
		}
		int ans = 0;
		rep(i, 0, 64)
			if(a[i] != b[i]) ans++;
		cout << ans << endl;
	}

	return 0;
}
