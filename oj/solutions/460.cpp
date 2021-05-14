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

pair<bool, vi> solve(
	int x1, int y1, int x2, int y2,
	int x3, int y3, int x4, int y4){
	pair<bool, vi> ans;
	ans.st = false;
	ans.nd = vi(4, 0);
	if(x3 >= x1 && x3 <= x2 && x4 <= x2 && y3 <= y1 && y4 >= y2)
		ans = mp(true, vi({x3, y1, x4, y2}));
	else if(x3 >= x1 && x3 < x2 && x4 >= x2 && y3 >= y1 && y3 < y2 && y4 >= y2)
		ans = mp(true, vi({x3, y3, x2, y2}));
	else if(x2 > x3 && x2 <= x4 && x1 <= x3 && y1 >= y3 && y1 < y4 && y2 >= y4)
		ans = mp(true, vi({x3, y1, x2, y4}));
	else if(x3 >= x1 && x3 <= x2 && x4 <= x2 && y3 <= y1 && y4 <= y2 && y4 > y1)
		ans = mp(true, vi({x3, y1, x4, y4}));
	else if(x3 >= x1 && x3 <= x2 && x4 <= x2 && y3 >= y1 && y3 < y2 && y4 >= y2)
		ans = mp(true, vi({x3, y3, x4, y2}));
	else if(x1 <= x3 && x2 <= x4 && x2 > x3 && y2 <= y4 && y2 >= y3 && y1 >= y3)
		ans = mp(true, vi({x3, y1, x2, y2}));
	else if(x3 >= x1 && x3 < x2 && x4 >= x2 && y4 <= y2 && y4 >= y1 && y3 >= y1)
		ans = mp(true, vi({x3, y3, x2, y4}));
	else if(x1 >= x3 && x1 <= x4 && x2 <= x4 && y2 <= y4 && y2 >= y3 && y1 >= y3)
		ans = mp(true, vi({x1, y1, x2, y2}));

	return ans;
}

int main() {

	fastio;

	int t, cas = 0;
	cin >> t;
	while(t--){
		if(cas)
			cout << endl;
		int x1, x2, x3, x4;
		int y1, y2, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		
		pair<bool, vi> ans = solve(x1, y1, x2, y2, x3, y3, x4, y4);
		if(!ans.st)
			ans = solve(x3, y3, x4, y4, x1, y1, x2, y2);
		if(ans.st)
			cout << ans.nd[0] << " " << ans.nd[1] << " " << 
			ans.nd[2] << " " << ans.nd[3] << endl;
		else
			cout << "No Overlap" << endl;
		cas++;
	}

	return 0;
}