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

int m, n;
string pat = "IEHOVA#";
int mi[4] = {0, 0, -1, 1};
int mj[4] = {1, -1, 0, 0};
string mov[4] = {"right", "left", "forth", "forth"};
string s[10];

bool valid(int i, int j){
	if(i >= 0 && i < m && j >=0 && j < n)
		return true;
	return false;
}

ii get(char c){
	ii res = {0, 0};
	rep(i, 0, m){
		rep(j, 0, n){
			if(s[i][j] == c){
				res = mp(i, j);
				break;
			}
		}
	}
	return res;
}

void dfs(ii u, int idx){
	if(idx == (int)pat.size())
		return;
	rep(i, 0, 4){
		int a = u.st+mi[i];
		int b = u.nd+mj[i];
		ii v = mp(a, b);
		if(valid(a, b) && s[a][b] == pat[idx]){
			cout << mov[i] << (idx == (int)pat.size()-1 ? "\n" : " ");
			dfs(v, idx+1);
		}
	}
}

int main() {

	fastio;
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		rep(i, 0, m) cin >> s[i];
		ii source = get('@');
		dfs(source, 0);
	}

	return 0;
}




