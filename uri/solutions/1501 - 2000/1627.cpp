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

bool solve(int at, int ad, int bt, int bd, int h){
	int t = 0;
	bool ans = true;
	while(h > 0){
		if(t%ad == 0 && t%bd == 0){
			if(h - at <= 0){
				ans = true;
				break;
			}
			h -= at;
			if(h - bt <= 0){
				ans = false;
				break;
			}
			h -= bt;
		}else if(t%ad == 0){
			h -= at;
			if(h <= 0)
				ans = true;
		}else if(t%bd == 0){
			h -= bt;
			if(h <= 0)
				ans = false;
		}
		t++;
	}
	return ans;
}

int main()
{

	fastio;

	int t;
	cin >> t;
	while(t--){
		int at, ad, bt, bd, h;
		cin >> at >> ad >> bt >> bd >> h;
		if(solve(at, ad, bt, bd, h))
			cout << "Andre\n";
		else
			cout << "Beto\n";
	}

	return 0;
}