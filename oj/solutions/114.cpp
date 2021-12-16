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
#define MAX 100
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

class Bumper{
public:
	int c, v;
	void setbumper(int _v, int _c){
		c = _c; v = _v;
	}
};

class Ball{
public:
	int d, l;
	void setball(int _d, int _l){
		d = _d; l = _l;
	}
};

int m, n, w, p;
map<ii, Bumper> bgrid;
map<int, int> turn = {
	{0, 3}, {1, 0}, {2, 1}, {3, 2}
};
map<int, ii> mov = {
	{0, {1, 0}}, {1, {0, 1}}, 
	{2, {-1, 0}}, {3, {0, -1}}
};

bool valid(int i, int j){
	if(i >= 1 && i <= m && j >= 1 && j <= n)
		return true;
	return false;
}

bool wall(int i, int j){
	if(i == 1 || i == m || j == 1 || j == n)
		return true;
	return false;
}

int simulate(pair<ii, Ball> ball){
	int points = 0;
	int x = ball.st.st;
	int y = ball.st.nd;
	int d = ball.nd.d;
	int l = ball.nd.l;
	while(l > 0){
		if(valid(x + mov[d].st, y + mov[d].nd)){
			x += mov[d].st;
			y += mov[d].nd;
			if(wall(x, y)){
				x -= mov[d].st;
				y -= mov[d].nd;
				l -= w;
				d = turn[d];
			}else if(bgrid.find({x, y}) != bgrid.end()){
				if(l > 1){
					points += bgrid[{x, y}].v;
					l -= bgrid[{x, y}].c;
					x -= mov[d].st;
					y -= mov[d].nd;
					d = turn[d];
				}
			}
		}
		l--;
	}
	return points;
}

int main() {

	fastio;

	cin >> m >> n;
	cin >> w >> p;

	rep(i, 0, p){
		int x, y, c, v;
		cin >> x >> y >> v >> c;
		Bumper b; b.setbumper(v, c);
		bgrid[{x, y}] = b;
	}

	int x, y, d, l;
	int ans = 0;
	while(cin >> x >> y >> d >> l){
		Ball b; b.setball(d, l);
		int points = simulate({{x, y}, b});
		cout << points << endl;
		ans += points;
	}
	cout << ans << endl;

	return 0;
}
