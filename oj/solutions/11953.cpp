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

int n;
string field[101];
int mi[4] = {0, 0, -1, 1};
int mj[4] = {1, -1, 0, 0};

bool valid(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}

ii count(int i, int j, int k, ii p){
	while(valid(i, j) && field[i][j] != '.'){
		if(field[i][j] == 'x')
			p.st++;
		else
			p.nd++;
		field[i][j] = '.';
		i += mi[k];
		j += mj[k];
	}
	return p;
}

int main() {

	fastio;

	int t;
	cin >> t;

	rep(l, 1, t+1){
		cout << "Case " << l << ": ";
		cin >> n;
		rep(i, 0, n) cin >> field[i];
		int ans = 0;
		rep(i, 0, n){
			rep(j, 0, n){
				if(field[i][j] == 'x' || field[i][j] == '@'){
					int arr = (field[i][j] == '@' ? 1 : 0), ex = (field[i][j] == 'x' ? 1 : 0);
					ii p = {ex, arr};
					field[i][j] = '.';
					rep(k, 0, 4){
						int a = i+mi[k], b = j+mj[k];
						if(valid(a, b) && (field[a][b] == 'x' || field[a][b] == '@')){
							p = count(a, b, k, p);
							break;
						}
					}
					if(p.st != 0)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}