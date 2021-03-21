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
	double prices[n];
	rep(i, 0, n){
		double p;
		int g;
		cin >> p >> g;
		prices[i] = (1000.0/g)*p;
	}

	cout << fixed << setprecision(2) << *min_element(prices, prices+n) << endl;

	return 0;
}