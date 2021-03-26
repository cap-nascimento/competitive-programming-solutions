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
#define MAX 10010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int solve(set<string>& v, string s){
	int m = 0;
	while(m < MAX){
		int sn = stoi(s);
		sn *= sn;
		string ns = to_string(sn);
		while(ns.size() < 2*s.size()){
			ns = "0" + ns;
		}
		s = ns.substr((ns.size()/4), ns.size()/2);
		if(v.find(s) != v.end())
			break;
		v.insert(s);
		m++;
	}
	return v.size();
}

int main() {

	fastio;
	string s;
	while(cin >> s && s.compare("0")){
		set<string> v;
		v.insert(s);
		cout << solve(v, s) << endl;
	}

	return 0;
}