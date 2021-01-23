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

	int a[n];

	rep(i, 0, n)
		cin >> a[i];

	int l=0, r=n-1;

	int s=0, d=0;
	bool turn = true;
	while(l <= r){
		int v = 0;
		if(a[l] > a[r]){
			v = a[l];
			l++;
		}else{
			v = a[r];
			r--;
		}
		if(turn)
			s += v;
		else
			d += v;
		turn = !turn;
	}

	cout << s << " " << d << endl;

	return 0;
}