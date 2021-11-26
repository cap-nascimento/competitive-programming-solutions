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
#define MAX 100010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

bool compare(pair<string, int>&a, pair<string, int>&b){
	if(a.st == b.st)
		return a.nd < b.nd;
	if(a.st.substr(0, 2) == "23" && b.st.substr(0, 2) == "23")
		return stoi(a.st.substr(3, 2)) < stoi(b.st.substr(3, 2));
	if(a.st.substr(0, 2) == "00" && b.st.substr(0, 2) == "00")
		return stoi(a.st.substr(3, 2)) < stoi(b.st.substr(3, 2));
	if(a.st.substr(0, 2) == "23" && b.st.substr(0, 2) == "00")
		return true;
	return false;
}

int main() {

	fastio;

	int p, q;
	cin >> p >> q;
	int bf = 60-p;
	int af = p;

	vector<pair<string, string>> povo;
	rep(i, 0, q){
		string h, name;
		cin >> h >> name;
		if(h.substr(0, 2) == "23" && stoi(h.substr(3, 2)) >= bf)
			povo.pb(mp(h, name));
		if(h.substr(0, 2) == "00" && stoi(h.substr(3, 2)) <= af)
			povo.pb(mp(h, name));
	}

	vector<pair<string, int>> povo2;
	rep(i, 0, povo.size()){
		povo2.pb(mp(povo[i].st, i));
	}
	sort(povo2.begin(), povo2.end(), compare);
	for(auto x : povo2){
		cout << povo[x.nd].nd << endl;
	}

	return 0;
}
