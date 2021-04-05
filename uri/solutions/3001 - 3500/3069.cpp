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

bool compare(ii a, ii b){
	if(a.st == b.st)
		return a.nd > b.nd;
	return a.st < b.st;
}

int main()
{
	int p, s, cas = 1;
	while(cin >> p >> s && (p || s)){
		vector<ii> v(s);
		rep(i, 0, s){
			int U, V;
			cin >> U >> V;
			v[i] = mp(U, V);
		}
		sort(v.begin(), v.end(), compare);
		int l = v[0].st, r = v[0].nd;
		set<ii> ans;
		rep(i, 1, s){
			if(v[i].st > r){
				ans.insert(mp(l, r));
				l = v[i].st;
				r = v[i].nd;
			}else
				r = max(r, v[i].nd);
		}
		ans.insert(mp(l, r));
		cout << "Teste " << cas++ << endl;
		for(auto x : ans){
			cout << x.st << " " << x.nd << endl;
		}
		cout << endl;
	}

	return 0;
}