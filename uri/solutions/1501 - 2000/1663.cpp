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
    while(cin >> n && n){
        int v[n], a[n];
        rep(i, 0, n){
            cin >> v[i];
            a[v[i]-1] = i+1;
        }
        bool ans = true;
        rep(i, 0, n) if(a[i] != v[i]) ans = false;

        if(ans)
            cout << "ambiguous\n";
        else
            cout << "not ambiguous\n";
    }


	return 0;
}