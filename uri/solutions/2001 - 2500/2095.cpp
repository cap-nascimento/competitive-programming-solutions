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

int main() {

	fastio;
	
	int n;
	cin >> n;
	vi Q(n), N(n);

	rep(i, 0, n) cin >> Q[i];
	rep(i, 0, n) cin >> N[i];
	sort(Q.begin(), Q.end());
	sort(N.begin(), N.end());
	
	int ans = 0, k = 0;
	rep(i, 0, n){
		int pos = upper_bound(N.begin()+k, N.end(), Q[i]) - N.begin();
		if(pos < n){
			ans++; k = pos+1;
		}
	}
	cout << ans << endl;

	return 0;
}
