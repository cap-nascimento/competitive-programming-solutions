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

vi fib;
void pre(){
    int a = 1, b = 1, c = a+b;
    fib.pb(a);
    do{
        c = a+b;
        fib.pb(c);
        a = b;
        b = c;
    }while(c <= 1000);
}

int main() {

	fastio;
    pre();
    int n, m;
    while(cin >> n >> m){
        int ans = 0;
        vi v(n);
        rep(i, 0, n) cin >> v[i];
        for(int i=n-1, j = m;i>=0 && j>0;i--,j--){
            if(lower_bound(fib.begin(), fib.end(), v[i]) != fib.end()) ans += v[i];
        }
        cout << ans << endl;
    }

	return 0;
}
