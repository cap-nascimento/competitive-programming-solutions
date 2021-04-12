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

lld v[5];

lld gcd(lld a, lld b){
	return b == 0 ? a : gcd(b, a%b);
}

lld lcm(lld a, lld b){
	return (a*b)/gcd(a, b);
}

lld solve(lld x){
	lld sum = 0;

	for(lld msk=1;msk<(1<<5);msk++){
		lld mult = 1, bits = 0;
		for(int i=0;i<5;i++){
			if(msk & (1 << i)){
				bits++;
				mult = lcm(mult, v[i]);
			}
		}
		lld cur = x / mult;
		if(bits % 2 == 1)
			sum += cur;
		else
			sum -= cur;
	}

	return x-sum;
}

int main() {

	fastio;

	int t;
	cin >> t;

	while(t--){
		lld n, m, a, d;
		cin >> n >> m >> a >> d;
		v[0] = a;
		v[1] = a+d;
		v[2] = a+(2*d);
		v[3] = a+(3*d);
		v[4] = a+(4*d);
		cout << solve(m)-solve(n-1) << endl;
	}

	return 0;
}