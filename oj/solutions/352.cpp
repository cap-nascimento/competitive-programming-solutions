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
#define MAX 30
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

string m[MAX];
int n;
int mi[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}

void solve(int i, int j){
	m[i][j] = '0';
	rep(k, 0, 8){
		int a = i+mi[k];
		int b = j+mj[k];
		if(valid(a, b) && m[a][b] == '1')
			solve(a, b);
	}
}

int main() {

	fastio;

	int cas = 1;
	while(cin >> n){
		rep(i, 0, n)
			cin >> m[i];

		int c = 0;
		rep(i, 0, n){
			rep(j, 0, n){
				if(m[i][j] == '1'){
					solve(i, j);
					c++;
				}
			}
		}
		cout << "Image number " << cas++ << " contains " << c << " war eagles.\n";
	}

	return 0;
}