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

int n, m;
map<string, string> r;

int apply(string s){
	if(s.size() == 0)
		return 0;
	if(r.find(s) != r.end()){
		return s.size();
	}
	return apply(s.substr(0, s.size()-1));
}

int main() {

	fastio;

	cin >> n >> m;
	string bac = "A";
	rep(i, 0, m){
		string a, b;
		cin >> a >> b;
		r[a] = b;
	}
	while(n > 0){
		string a = "";
		rep(i, 0, bac.size()){
			size_t j = i;
			string s;
			while(j < bac.size() && bac[i] == bac[j]){
				s += bac[j];
				j++;
			}
			i = j-1;
			int x = apply(s);
			while(x){
				a += r[s.substr(0, x)];
				s = s.substr(x, s.size()-x);
				x = apply(s);
			}
		}
		bac = a;
		n--;
	}

	int A = 0, B = 0;
	rep(i, 0, bac.size()){
		if(bac[i] == 'A') A++;
		if(bac[i] == 'B') B++;
	}

	cout << A << " " << B << endl;

	return 0;
}