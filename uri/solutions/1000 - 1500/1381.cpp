/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define vi vector<int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define MAX 2000010
#define MOD 1300031
#define oo 0x7fffffff
#define ll long long int
#define endl '\n'
using namespace std;

ll n, c;
ll fat[MAX];

/*Modular inverse tools*/
ll gcdx(ll a, ll b, ll *x, ll *y){
 if(a == 0){*x = 0; *y = 1; return b;}
 ll x1, y1;
 ll gcd = gcdx(b%a, a, &x1, &y1);
 *x = y1 - (b/a)*x1;
 *y = x1;
 return gcd;
}

ll modular_inverse(ll b, ll m){
 ll x, y;
 ll g = gcdx(b, m, &x, &y);
 if(g != 1) return -1;
 return (x%m+m)%m;
}

ll modular_division(ll a, ll b, ll m){
 a = a%m;
 ll inv = modular_inverse(b, m);
 return (inv*a)%m;
}

int main() {
 fastio;
 fat[0] = 1;
 rep(i, 1, MAX) fat[i] = (fat[i-1]*1ULL*i)%MOD;
 int t;
 cin >> t;
 while(t--){
  ll n, c;
  cin >> n >> c;
  ll num = fat[n+c-1];
  ll den = (fat[n-1]*fat[c])%MOD;
  ll ans = modular_division(num, den, MOD);
  cout << ans << endl;
 }
 return 0;
}
