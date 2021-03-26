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

	vector<string> v;
	string s;
	while(getline(cin, s)){
		stringstream iss(s);
		string w;
		while(iss >> w) v.pb(w);
	}

	string line = "";
	vector<string> tot;
	string hr = "";
	rep(i, 0, 80) hr += "-";
	rep(i, 0, v.size()){
		if(v[i] == "<br>"){
			int j = i;
			while(j < v.size() && v[j] == v[i]){
				if(j == i){
					if(line.size() > 0){
						tot.pb(line.substr(0, line.size()-1)+"\n");
						line = "";
					}else if(line == "" && tot.size() == 0){
						tot.pb("\n");
					}else{
						string s = tot[tot.size()-1];
						if(s.substr(0, s.size()-1) == hr)
							tot.pb("\n");
					}
				}else{
					tot.pb("\n");
				}
				j++;
			}
			i = j-1;
		}else if(v[i] == "<hr>"){
			if(line.size() > 0){
				tot.pb(line.substr(0, line.size()-1)+'\n');
				line = "";
			}
			tot.pb(hr + '\n');
		}else{
			if(line.size() + (v[i].size()+1) == 80 || line.size() + v[i].size() == 80){
				tot.pb(line + v[i] + '\n');
				line = "";
			}else if(line.size() + v[i].size() > 80){
				tot.pb(line.substr(0, line.size()-1) + '\n');
				line = v[i]+" ";
			}else{
				line += v[i]+" ";
			}
		}
	}
	if(line.size() > 0) tot.pb(line.substr(0, line.size()-1) + "\n");
	rep(i, 0, tot.size()){
		cout << tot[i];
	}

	return 0;
}






