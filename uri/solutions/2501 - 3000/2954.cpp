/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <iostream>
#include <vector>
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

int max_points(string & s, string pat, int ans){
 int ccount = 0;
 int sz = pat.size();
 rep(i, 0, s.size()){
  if(s[i] != ' ') ccount++;
  if(s[i] == '@'){
   if(i != 0 && s[i-1] != ' ')
    continue;

   if((i+sz == (int)s.size()) || (i+sz < (int)s.size() && s[i+sz] == ' ')){
    ans = max(ccount+(sz-1), ans);
    s[i] = pat[0];
    ccount = 0;
    i += (sz-1);
   }
  }
 }
 return ans;
}

int main() {
 fastio;
 int n;
 cin >>n;
 cin.ignore();
 while(n--){
  string s;
  getline(cin, s);
  rep(i, 0, s.size()){
   s[i] = tolower(s[i]);
   if((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z'))
    s[i] = ' ';
  }
  int pos;
  while((pos = s.find("jogo")) != string::npos)  s[pos] = '@';
  int ans = max_points(s, "jogo", 0);
  
  while((pos = s.find("perdi")) != string::npos) s[pos] = '@';
  ans = max_points(s, "perdi", ans);
  cout << ans << endl;
 }
 return 0;
}
