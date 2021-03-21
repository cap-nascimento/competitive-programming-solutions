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
	int n;
	while(cin >> n){
		string s, w, f;
		map<string, set<string>> m;
		cin.ignore(1);
		rep(i, 0, n){
			getline(cin, s);
			stringstream iss(s);
			int j = 0;
			while(iss >> w){
				if(j == 0){
					f = w;
					m[f] = {};
				}else{
					m[f].insert(w);
				}
				j++;
			}
		}
		while(getline(cin, s)){
			int pos = s.find(' ');
			w = s.substr(0, pos);
			f = s.substr(pos+1, s.size());
			if(m[w].find(f) != m[w].end())
				cout << "Uhul! Seu amigo secreto vai adorar o/\n";
			else
				cout << "Tente Novamente!\n";
		}
	}

	return 0;
}