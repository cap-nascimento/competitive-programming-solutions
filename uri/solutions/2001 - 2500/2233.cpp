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

int h[6] = {10, 11, 12, 13, 14, 15};

lld pot(lld a, lld b){
	lld ans = 1;
	rep(i, 0, b) ans *= a;
	return ans;
}

lld todec(string s){
	lld ans = 0, exp = 0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i] >= '0' && s[i] <= '9')
			ans += (s[i]-'0')*pot(16, exp);
		else
			ans += (h[s[i]-'a'])*pot(16, exp);
		exp++;
	}
	return ans;
}

string tohex(lld x){
	stack<char> st;
	while(x > 0){
		lld r = x%16;
		x/=16;
		if(r >= 0 && r <= 9)
			st.push(r+'0');
		else{
			rep(i, 0, 6) if(h[i] == r) st.push(i+'a');
		}
	}
	string ans = "";
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	return ans;
}

int main() {

	fastio;

	string r, g, b;
	cin >> r >> g >> b;

	lld dr = todec(r);
	lld dg = todec(g);
	lld db = todec(b);

	//cout << dr << " " << dg << " " << db << endl;

	lld ans = 1;
	lld gs = dr/dg;
	ans += (gs*gs);
	lld bs = dg/db;
	ans += (gs*gs)*(bs*bs);

	cout << tohex(ans) << endl;

	return 0;
}
