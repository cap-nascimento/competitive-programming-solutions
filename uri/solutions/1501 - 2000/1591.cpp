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

// duas palavras iguais podem se sobrepor

int search(vector<string> v, string s){
	int ans = 0;
	rep(i, 0, v.size()){
		rep(j, 0, v[i].size()){
			//cout << j << endl;
			if(v[i][j] == s[0]){
				size_t k = j, idx = 0;
				while(v[i][k] == s[idx] && (k < v[i].size() && idx < s.size())){
					k++;
					idx++;
					//cout << k << endl;
				}
				if(idx == s.size()) ans++;
				//j = k-1;				
			}
		}
	}

	return ans;
}

int main() {

	//fastio;

	int t;
	cin >> t;
	while(t--){
		int l, c;
		vector<string> hor;
		vector<string> ver;
		cin >> l >> c;

		rep(i, 0, l){
			string s;
			cin >> s;
			hor.pb(s);
		}

		rep(i, 0, c){
			string s = "";
			rep(j, 0, l) s += hor[j][i];
			ver.pb(s);
		}

		int q;
		cin >> q;
		while(q--){
			string s;
			cin >> s;
			if(s.size() == 1)
				cout << search(hor, s) << endl;
			else
				cout << search(hor, s)+search(ver, s) << endl;
		}
	}

	return 0;
}