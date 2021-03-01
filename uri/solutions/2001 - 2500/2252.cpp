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

bool compare(pair<double, int> & a, pair<double, int> & b){
	if(a.st > b.st)
		return true;
	if(a.st < b.st)
		return false;
	return a.nd < b.nd;
}

int main() {

	fastio;

	int n, cas = 1;
	while(cin >> n){
		pair<double, int> v[10];
		rep(i, 0, 10){
			double x;
			cin >> x;
			v[i] = mp(x, i);
		}

		sort(v, v+10, compare);

		cout << "Caso " << cas++ << ": ";
		for(int i=0;i<n;i++) cout << v[i].nd;
		cout << endl;
	}

	return 0;
}
