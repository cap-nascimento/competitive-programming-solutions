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

int main() {

	fastio;

	string s;
	while(getline(cin, s)){
		string ans = "";
		rep(i, 0, s.size()/2) swap(s[i], s[s.size()-i-1]); 
		rep(i, 0, s.size()){
			ans += s[i];
			if(s[i] == '.' || s[i] == ','){
				if(i+1 < (int)s.size()){
					size_t j = i+1;
					while(j < s.size() && s[j] == ' '){
						if(j > i+1)
							ans += ' ';
						j++;
					}
					i = j-1;
				}
			}
		}
		rep(i, 0, ans.size()/2) swap(ans[i], ans[ans.size()-i-1]);
		cout << ans << endl;
	}

	return 0;
}