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

vector<lld> primes;
int a[MAX];
lld n, e, c;

// multiplicative inverse
lld gcdx(lld a, lld b, lld * x, lld * y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    lld x1, y1;
    lld gcd =  gcdx(b%a, a, &x1, &y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return gcd;
}

lld inverse(lld a, lld b){
    lld x, y;
    lld g = gcdx(a, b, &x, &y);
    return (x%b + b)%b;
}

// modular exponentiation (a^b)%c
lld modx(lld a, lld b, lld c){
    lld res = 1;
    a = a%c;
    if(a == 0) return 0;
    while(b > 0)
    {
        if(b & 1)
            res = (res*a)%c;
        b = b >> 1;
        a = (a*a)%c;
    }
    return res;
}

void sieve(){
    a[0] = a[1] = 0;
    for(int i=2;i*i<MAX;i++){
        if(a[i]){
            for(int j=i+i;j<MAX;j+=i){
                a[j] = 0;
            }
        }
    }
    rep(i, 0, MAX) if(a[i]) primes.pb(i);
}

int main() {

	fastio;
    memset(a, 1, sizeof(a));
    sieve();

    cin >> n;
    cin >> e;
    cin >> c;
    lld tot = 0;
    for(size_t i=0;i<primes.size();i++){
        if(n%primes[i] == 0){
            size_t pos = lower_bound(primes.begin(), primes.end(), n/primes[i]) - primes.begin();
            if(pos < primes.size() && primes[pos]*primes[i] == n){
                tot = (primes[pos]-1)*(primes[i]-1);
                break;
            }
        }
    }
    lld d = inverse(e, tot);
    cout << modx(c, d, n) << endl;

	return 0;
}