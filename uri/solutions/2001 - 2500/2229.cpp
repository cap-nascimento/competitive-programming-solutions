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

	int v[16];
	v[0] = 4;
	rep(i, 1, 16){
		int s = sqrt(v[i-1]);
		v[i] = (2*s-1)*(2*s-1);
	}

	int n, t = 1;
	while(cin >> n && !(n == -1)){
		cout << "Teste " << t++ << endl;
		cout << v[n] << "\n\n";
	}

	return 0;
}