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
	while(cin >> n){
		map<lld, lld> m;
		rep(i, 0, n){
			lld x; cin >> x;
			m[x]++;
		}
		vector<lld> ans;
		for(auto p : m){
			if(p.nd%2 != 0){
				ans.pb(p.st);
			}
		}
		rep(i, 0, ans.size()) 
			cout << ans[i] << (i == (int)ans.size()-1 ? '\n' : ' ');
	}
	
	return 0;
}