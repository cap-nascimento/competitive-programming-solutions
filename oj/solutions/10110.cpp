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
#define oo 4294967295
#define lld long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;

	vector<lld> v = {1};
	lld s = 3;
	while(v[v.size()-1] <= oo){
		v.pb(v[v.size()-1]+s);
		s += 2;
	}
	lld n;
	while(cin >> n && n){
		size_t pos = lower_bound(v.begin(), v.end(), n) - v.begin();
		if(pos < v.size() && v[pos] == n)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}