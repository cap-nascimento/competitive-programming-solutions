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

	int n, m;
	cin >> n >> m;
	int a[n] = {0};

	rep(i, 0, m){
		int p, d;
		cin >> p >> d;
		a[p-1] = 1;
		for(int i=p-1+d;i<n;i+=d) a[i] = 1;
		for(int i=p-1-d;i>=0;i-=d) a[i] = 1;
	}

	rep(i, 0, n){
		cout << a[i] << '\n';
	}

	return 0;
}