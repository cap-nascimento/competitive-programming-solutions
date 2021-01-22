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
	string a, b;
	cin >> a >> b;

	rep(i, 0, a.size()) a[i] = tolower(a[i]);
	rep(i, 0, b.size()) b[i] = tolower(b[i]);

	if(a < b)
		cout << -1 << endl;
	else if(a > b)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}