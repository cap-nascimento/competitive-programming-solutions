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

class Pattern{
public:
	vector<string> pat; int n;
	void set_pattern(int _n, char _pat[][MAX]){
		int n = _n;
		pat.assign(n, "");
		rep(i, 0, n) {
			string s = "";
			rep(j, 0, n) s += _pat[i][j];
			pat[i] = s;
		}
	}
};

char grid[MAX][MAX], rotated[MAX][MAX];
int n;

void rotate_grid(){
	rep(i, 0, n){
		char tmp[n];
		rep(j, 0, n) tmp[j] = grid[j][i];
		int k = 0;
		for(int j = n-1; j >= 0; j--){
			rotated[i][k] = tmp[j]; k++;
		}
	}
	rep(i, 0, n) rep(j, 0, n) grid[i][j] = rotated[i][j];
}

void flip_grid_vertically(){
	int k = n-1;
	rep(i, 0, n){
		rep(j, 0, n) rotated[k][j] = grid[i][j];
		k--;
	}
	rep(i, 0, n) rep(j, 0, n) grid[i][j] = rotated[i][j];
}

void flip_grid_horizontally(){
	int k = n-1;
	rep(i, 0, n){
		rep(j, 0, n) rotated[j][k] = grid[j][i];
		k--;
	}
	rep(i, 0, n) rep(j, 0, n) grid[i][j] = rotated[i][j];
}

void pm(vector<string> m, int n){
	rep(i, 0, n){
		rep(j, 0, n){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool find_pattern(vector<Pattern> & v, Pattern key){
	pm(key.pat, n);
	rep(i, 0, v.size()){
		Pattern cur = v[i];
		pm(cur.pat, n);
		bool found = true;
		rep(j, 0, n)
			if(cur.pat[j] != key.pat[j])
				found = false;
		if(found) return true;
	}
	return v.size() == 0 ? false : true;
}


int main() {

	//fastio;

	while(cin >> n && n){
		rep(i, 0, n) rep(j, 0, n) grid[i][j] = '.';

		vector<Pattern> pats;
		int winner = -1;
		rep(i, 0, n*2){
			if(winner == -1){
			int x, y;
			char op;
			cin >> x >> y >> op;
			if(op == '+') grid[x-1][y-1] = '*';
			else grid[x-1][y-1] = '.';
			Pattern p;
			p.set_pattern(n, grid);
			if(!find_pattern(pats, p)){
				rep(j, 0, 4){
					rotate_grid();
					p.set_pattern(n, grid);
					pats.pb(p);
				}
				flip_grid_horizontally();
				rep(j, 0, 4){
					rotate_grid();
					p.set_pattern(n, grid);
					pats.pb(p);
				}
				flip_grid_horizontally();
				flip_grid_vertically();
				rep(j, 0, 4){
					rotate_grid();
					p.set_pattern(n, grid);
					pats.pb(p);
				}
				flip_grid_vertically();
			}else{
				winner = (i%2 == 0 ? 2 : 1);
				cout << "Player " << winner << " wins on move " << i+1 << endl;
			}
			}
		}
		if(winner == -1)
			cout << "Draw\n";

	}

	return 0;
}
