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

lld gcd(lld a, lld b){
	return b == 0 ? a : gcd(b, a%b);
}
lld lcm(lld a, lld b){
	return (a*b)/gcd(a, b);
}
int main() {

	fastio;

	int n, l;
	cin >> n >> l;
	vector<lld> v(n);
	rep(i, 0, n){
		int x; cin >> x;
		v[i] = (i == 0 ? x : lcm(x, v[i-1]));
	} 

	lld ans = v[n-1], idx = 1;
	rep(i, 1, l+1){
		lld x = lcm(v[n-1], i);
		if(x > ans && x <= l){
			ans = x;
			idx = i;
		}
	}

	cout << idx << endl;

	return 0;
}