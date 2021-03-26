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

int dist(ii a, ii b){
	return abs(a.st - b.st) + abs(a.nd - b.nd);
}

int main() {

	fastio;

	int n, k;
	cin >> n >> k;

	vector<pair<ii, int>> v;

	rep(i, 0, k){
		int x, y, d;
		cin >> x >> y >> d;
		v.pb(mp(mp(x, y), d));
	}

	vector<set<ii>> s;
	rep(h, 0, k){
		pair<ii, int> p = v[h];
		set<ii> a;
		rep(i, 0, n){
			rep(j, 0, n){
				if(dist(p.st, mp(i, j)) == p.nd)
					a.insert(mp(i, j));
			}
		}
		s.pb(a);
	}

	vector<ii> x(s[0].begin(), s[0].end());
	rep(i, 1, s.size()){
		vector<ii> a(s[i].begin(), s[i].end());
		vector<ii> b(x.size()+a.size());
		vector<ii>::iterator it;
		it = set_intersection(x.begin(), x.end(), a.begin(), a.end(), b.begin());
		b.resize(it-b.begin());
		x.resize(0);
		rep(i, 0, b.size()) x.pb(b[i]);
	}

	if(x.size() == 1)
		cout << (*x.begin()).st << " " << (*x.begin()).nd << endl;
	else
		cout << -1 << " " << -1 << endl;


	return 0;
}

