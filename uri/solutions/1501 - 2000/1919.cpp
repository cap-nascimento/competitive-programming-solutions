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
#define MAX 1e2
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	vector<string> v;
 	string s = "";	
	rep(i, 0, 10)
		rep(j, i+1, 10)
			rep(k, j+1, 10)
				rep(l, k+1, 10)
					rep(m, l+1, 10)
						v.pb(s + (char)(i+'0') + (char)(j+'0') + (char)(k+'0') + (char)(l+'0') + (char)(m+'0'));
	
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		bool has = false;
		rep(i, 0, v.size()){
			s = v[i];
			int sum = 0;
			do {
				sum += stoi(s);
			} while (next_permutation(s.begin(), s.end()));
			if(sum == k){
				cout << "{" << s[0] << "," << s[1] << "," << s[2]<< "," << s[3] << "," << s[4] << "}" << endl;
				has = true;
			}
		}
		if(!has) cout << "impossivel\n";
		cout << endl;
	}
	return 0;
}
