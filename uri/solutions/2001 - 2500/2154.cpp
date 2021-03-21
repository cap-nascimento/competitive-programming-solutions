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

string solve(string w){
	size_t pos = w.find('x');
	int c = stoi(w.substr(0, pos));
	int e = stoi(w.substr(pos+1, w.size()));
	c *= e;
	e--;
	string ans = to_string(c) + "x";
	if(e > 1) ans += to_string(e);
	return ans;
}

int main() {

	fastio;
	int n;
	while(cin >> n){
		cin.ignore(1);
		string s, w;
		getline(cin, s);
		//cout << n << " " << s << endl;
		stringstream iss(s);
		int a = 0;
		string ans = "";
		while(iss >> w){
			if(a%2 == 0){
				ans += solve(w) + " ";
			}else ans += "+ ";
			a++;
		}
		ans[ans.size()-1] = '\n';
		cout << ans;
	}

	return 0;
}