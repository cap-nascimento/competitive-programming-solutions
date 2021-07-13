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

map<char, int> m;
string R;
int pot[63][1030];
void pre(){
 char c = 'A';
 rep(i, 10, 36){ m[c] = i; c++;}
 c = 'a';
 rep(i, 36, 62){ m[c] = i; c++;}
 c = '0';
 rep(i, 0, 10){ m[c] = i; c++; }
}

void set_pot(){
 rep(i, 0, 1030){ pot[0][i] = 0; pot[1][i] = 1;}
 rep(i, 2, 63){
  pot[i][0] = 1;
  rep(j, 1, 1030)
   pot[i][j] = (pot[i][j-1]*i)%(i-1);
 }
}

bool convert(int n){
 int ans = 0;
 int exp = 0;
 for(int i=R.size()-1;i>=(R[0]=='-'?1:0);i--){
  ans = (ans + m[R[i]]*pot[n][exp++])%(n-1);
 }
 if(ans == 0) return true;
 return false;
}

int solve(){
 int initial = 1;
 rep(i, 0, R.size()) initial = max(initial, m[R[i]]);
 rep(i, initial+1, 63){
  if(convert(i))
   return i;
 }
 return -1;
}

int main() {
 fastio;
 pre();
 set_pot();
 while(cin >> R){
  int res = solve();
  if(res == -1)
   cout << "such number is impossible!" << endl;
  else
   cout << res << endl;
 }

 return 0;
}
