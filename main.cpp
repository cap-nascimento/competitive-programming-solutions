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
#define MAX 100010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;

	int b, g;
	cin >> b >> g;
	int n = floor(g/2.0);
	if(b >= n)
		cout << "Amelia tem todas bolinhas!\n";
	else
		cout << "Faltam " << n-b << " bolinha(s)\n";

	return 0;
}
