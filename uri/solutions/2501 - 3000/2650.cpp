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
	int n, h;
	cin >> n >> h;
	cin.ignore(1);
	rep(i, 0, n){
		string line;
		getline(cin, line);
		stringstream iss(line);
		string w;
		vector<string> name;
		while(iss >> w){
			name.pb(w);
		}
		int th = stoi(name[name.size()-1]);
		if(th > h){
			rep(i, 0, name.size()-1)
				cout << name[i] << (i == (int)name.size()-2 ? '\n' : ' ')	;
		}
	}

	return 0;
}