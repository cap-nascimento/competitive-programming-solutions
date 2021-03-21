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
#define MAX 100
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

string key[61];
set<string> song;
string scale[12] = {"do", "do#", "re", "re#", "mi",
					"fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int intervals[7] = {2, 2, 1, 2, 2, 2, 1}, n;
vector<set<string>> scales(12);
string solve(){
	rep(i, 0, 12){
		size_t c = 0;
		for(auto s : song){
			if(scales[i].find(s) != scales[i].end())
				c++;
		}
		if(c == song.size())
			return key[i];
	}
	return "desafinado";
}

int main() {

	fastio;

	rep(i, 0, 61) key[i] = scale[i%12];
	rep(i, 0, 12){
		scales[i].insert(key[i]);
		int j = i;
		rep(k, 0, 7){
			scales[i].insert(key[j+intervals[k]]);
			j += intervals[k];
		}
	}

	cin >> n;
	rep(i, 0, n){
		int x;
		cin >> x;
		song.insert(key[x-1]);
	}

	cout << solve() << endl;

	return 0;
}