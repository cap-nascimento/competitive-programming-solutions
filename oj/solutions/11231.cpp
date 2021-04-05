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

void count(int * x, int d){
	while(d > 7){
		*x += (d-7);
		d-=2;
	}
}

int main()
{

	fastio;

	int n, m, b;
	while(cin >> n >> m >> b && (n || m || b)){
		vi l(m + n-1);
		int st = 1, col = 1;
		rep(i, 0, (m + n-1)){
			if(col < min(n, m)) l[i] = st++;
			if(col >= min(n, m) && col <= max(n, m)) l[i] = st;
			if(col > max(n, m)) l[i] = --st;
			col++;
		}
		int j = 0;
		lld ans = 0;
		if((b && m%2 == 0) || (!b && m%2 != 0)) j++;
		for(size_t i = j;i<l.size();i+=2)
			ans += (l[i]-7 > 0 ? l[i]-7 : 0);
		cout << ans << endl;
	}

	return 0;
}