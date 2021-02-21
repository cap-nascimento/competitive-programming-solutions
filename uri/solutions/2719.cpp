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

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		deque<int> q;
		rep(i, 0, n){
			int x; cin >> x;
			q.pb(x);
		}

		int ans = 0, sum = 0;
		while(!q.empty()){
			int p = q.front();
			q.pop_front();
			sum += p;
			if(sum > m){
				ans++;
				sum = 0;
				q.push_front(p);
			}else if(sum == m){
				sum = 0;
				ans++;
			}
		}
		if(sum > 0 && sum < m) ans++;
		cout << ans << endl;
	}

	return 0;
}