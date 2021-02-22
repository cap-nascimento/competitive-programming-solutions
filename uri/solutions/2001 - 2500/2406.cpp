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
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;

		stack<char> s;
		set<char> open = {'(', '{', '['};
		map<char, char> clos = {
			mp(')', '('), mp('}', '{'), mp(']', '[')
		};

		bool ans = true;
		rep(i, 0, a.size()){
			if(!ans) break;
			if(open.find(a[i]) != open.end()){
				s.push(a[i]);
			}else{
				char c = (*clos.find(a[i])).nd;
				if(!s.empty() && c == s.top())
					s.pop();
				else
					ans = false;
			}
		}

		if(ans == false || !s.empty())
			cout << "N\n";
		else
			cout << "S\n";
	}

	return 0;
}
