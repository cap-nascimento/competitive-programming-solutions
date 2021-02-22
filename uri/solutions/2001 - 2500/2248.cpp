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

bool compare(ii x, ii y){
	if(x.nd == y.nd)
		return x.st < y.st;
	return x.nd > y.nd;
}

int main() {

	fastio;

	int n, t = 1;
	while(cin >> n && n){
		vector<ii> a;
		vi codes;
		rep(i, 0, n){
			int c, m;
			cin >> c >> m;
			codes.pb(c);
			a.pb(mp(i, m));
		}
		sort(a.begin(), a.end(), compare);
		cout << "Turma " << t << endl;
		vi ans;
		int i = 0;
		while(a[i].nd == a[0].nd && i < n){
			ans.pb(codes[a[i].st]);
			i++;
		}
		rep(i, 0, ans.size()){
			cout << ans[i] << ' ';
		}
		cout << "\n\n";
		t++;
	}

	return 0;
}
