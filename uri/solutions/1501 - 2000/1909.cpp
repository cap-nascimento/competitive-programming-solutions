/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <iostream>
#include <set>
#include <vector>
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
#define lld long long int
#define endl '\n'
using namespace std;

int n, t;
lld v[MAX];

lld gcd(lld a, lld b){
	return b == 0 ? a : gcd(b, a%b);
}

lld mmc(lld a, lld b){
	return (a*b)/gcd(a, b);
}

int solve(){
	lld m = v[0];
	int ma[t+1];
	rep(i, 0, t+1) ma[i] = 0;
	ma[v[0]] = 1;
	rep(i, 1, n){
		m = mmc(m, v[i]);
		ma[v[i]] = 1;
	}
	rep(i, 2, t+1) if(mmc(i, m) == t && !ma[i]) return i;
	return -1;
}

int main() {

	fastio;

	while(cin >> n >> t && (n || t)){
		rep(i, 0, n) cin >> v[i];

		int res = solve();
		if(res == -1)
			cout << "impossivel\n";
		else
			cout << res << endl;
	}

	return 0;
}
