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

int m[15][15];

int solve(int n){

    // lines & columns
    vi sums;
    rep(i, 0, n){
        int s1 = 0;
        int s2 = 0;
        rep(j, 0, n){
            s1 += m[i][j];
            s2 += m[j][i];
        }
        sums.pb(s1);
        sums.pb(s2);
    }
    rep(i, 0, sums.size()) if(sums[i] != sums[0]) return -1;
    // diagonals
    int s1=0, s2=0;
    rep(i, 0, n){
        rep(j, 0, n){
           if(i == j) s1 += m[i][j];
           if((j+i+1) == n) s2 += m[i][j];
        }
    }
    if(s1 != s2 || (s1 != sums[0] || s2 != sums[0])) return -1;
    return sums[0];
}

int main() {

	fastio;
    int n;
    cin >> n;

    rep(i, 0, n){
        rep(j, 0, n){
            cin >> m[i][j];
        }
    }

    cout << solve(n) << endl;

	return 0;
}