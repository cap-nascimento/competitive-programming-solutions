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

bool compare(int &a, int &b){
	return abs(a) > abs(b);
}

int main() {

	fastio;
	int p;
	cin >> p;
	while(p--){
		int n;
		cin >> n;
		int a[n];
		rep(i, 0, n){
			cin >> a[i];
		}
		sort(a, a+n, compare);
		int ans = 1;
		int f = (a[0] < 0 ? 0 : 1);
		rep(i, 1, n){
			if(f){
				if(a[i] < 0){
					ans++;
					f = 1-f;
				}
			}else{
				if(a[i] > 0){
					ans++;
					f = 1-f;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}