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
	bool who[n] = {false};
	string s;
	cin >> s;

	rep(i, 0, n){
		int j = i+1;
		while(s[j] == s[i] && j < n){
			who[j] = true;
			j++;
		}
		i = j-1;
	}
	int ans = 0;
	rep(i, 0, n){
		if(who[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}