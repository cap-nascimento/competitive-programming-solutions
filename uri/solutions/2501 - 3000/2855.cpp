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
#define MAX 100
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;

	int n;
	while(cin >> n)	{
		vi a(n);
		rep(i, 0, n){
			cin >> a[i];
		}
		size_t jump = 2;
		vi tmp;
		while(jump <= a.size()){
			tmp.resize(0);
			rep(i, 0, a.size()) tmp.pb(a[i]);
			for(size_t i=jump-1;i<tmp.size(); i += jump){
				tmp[i] = -1;
			}
			a.resize(0);
			rep(i, 0, tmp.size()) if(tmp[i] != -1) a.pb(tmp[i]);
			jump++;
		}
		set<int> b;
		rep(i, 0, a.size()) b.insert(a[i]);
		int q;
		cin >> q;
		if(b.find(q) != b.end())
			cout << "Y\n";
		else cout << "N\n";
	}

	return 0;
}
