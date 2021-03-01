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

double solve(double d, double x){
	double acc = .0;
	while(acc < d) acc += x;
	if(acc == d) return .0;
	acc -= x;
	return d - acc;
}

int main() {

	fastio;

	int t;
	cin >> t;
	while(t--){
		double d;
		int n;
		cin >> d >> n;
		double ans = .0;
		rep(i, 0, n){
			double x;
			cin >> x;
			if(x > d)
				continue;
			ans = max(ans, solve(d, x));
		}
		cout << fixed << setprecision(2) << ans << endl;
	}

	return 0;
}