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
    int x, y, cas = 1;
    while(cin >> x >> y && (x && y)){
        cout << "Teste " << cas++ << endl;
        vi m(x);
        rep(i, 0, x) cin >> m[i];
        vi s(x);
        s[0] = m[0];
        rep(i, 1, x){
            s[i] = s[i-1]+m[i];
        }
        int l = 0, r = y-1;
        vi v;
        while(r < x){
            int res;
            if(l == 0){
                res = ((double)s[r]/y);
            }else
            {
                res = ((double)(s[r]-s[l-1])/y);
            }
            v.pb(res);
            l++;
            r++;
        }
        sort(v.begin(), v.end());
        cout << v[0] << " " << v[v.size()-1] << "\n\n";
    }

	return 0;
}

