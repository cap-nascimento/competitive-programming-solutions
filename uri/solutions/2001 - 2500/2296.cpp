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

int main() {

	fastio;
	int n;
	cin >> n;
	pair<int, int> v[n];
	rep(i, 0, n){
		int m;
		cin >> m;
		vi h(m);
		rep(i, 0, m) cin >> h[i];
		int l = 0, r = 0;
		// left to right
		rep(i, 1, m) l = l + (h[i] > h[i-1] ? (h[i]-h[i-1]) : 0);
		// right to left
		for(int i=m-2;i>=0;i--) r = r + (h[i] > h[i+1] ? (h[i]-h[i+1]) : 0);
		v[i] = mp(min(l, r), i+1);
	}

	sort(v, v+n);

	cout << v[0].nd << endl;

	return 0;
}