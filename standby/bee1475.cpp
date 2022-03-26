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
#define MAX 1010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int N, C, T1, T2;

int main() {

	fastio;

	while(cin >> N >> C >> T1 >> T2){
		int a[N];
		rep(i, 0, N) cin >> a[i];

		if(N == 1)
			cout << min(T1, T2) << endl;
		else {
            int ans = 0;
			rep(i, 0, N) {
				int j = i+1;
                while(a[j] - a[i] <= max(T1, T2) && j < N) j++;
                j--;
                if(i == j)
                    ans += min(T1, T2);
                else
                    ans += max(T1, T2);
                i = j;
			}
            cout << ans << endl;
		}
	}

	return 0;
}
