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

map<string, lld> nm;

void pre(){
	nm["zero"] = 0; nm["um"] = 1; nm["dois"] = 2; nm["tres"] = 3; nm["quatro"] = 4;
	nm["cinco"] = 5; nm["seis"] = 6; nm["sete"] = 7; nm["oito"] = 8; nm["nove"] = 9;
	nm["dez"] = 10; nm["onze"] = 11; nm["doze"] = 12; nm["treze"] = 13; nm["quatorze"] = 14;
	nm["quinze"] = 15; nm["dezesseis"] = 16; nm["dezessete"] = 17; nm["dezoito"] = 18;
	nm["dezenove"] = 19; nm["vinte"] = 20; nm["trinta"] = 30; nm["quarenta"] = 40;
	nm["cinquenta"] = 50; nm["sessenta"] = 60; nm["setenta"] = 70; nm["oitenta"] = 80;
	nm["noventa"] = 90; nm["cem"] = 100; nm["cento"] = 100; nm["duzentos"] = 200;
	nm["trezentos"] = 300; nm["quatrocentos"] = 400; nm["quinhentos"] = 500;
	nm["seiscentos"] = 600; nm["setecentos"] = 700; nm["oitocentos"] = 800; nm["novecentos"] = 900;
	nm["mil"] = 1000; nm["milhao"] = 1000000; nm["milhoes"] = 1000000; nm["bilhao"] = nm["bilhoes"] = 1000000000;
	nm["trilhao"] = nm["trilhoes"] = 1000000000000;
}

int main() {

	fastio;
	pre();
	string s;
	while(getline(cin, s) && !cin.eof()){
		stringstream ss(s);
		string w;
		vector<lld> v;
		vector<string> vs;
		while(ss >> w){
			if(nm.find(w) != nm.end()){
				v.pb(nm[w]);
				vs.pb(w);
			}
		}
		vector<lld> x, y;
		lld ans = 0;
		for(int i=vs.size()-1;i>=0;i--){
			if(vs[i] == "milhoes" || vs[i] == "bilhoes" || vs[i] == "trilhoes" || vs[i] == "mil"){
				if(ans > 0){x.pb(ans); y.pb(1);}
				y.pb(0);
				x.pb(v[i]);
				ans = 0;				
			}else
				ans += v[i];
		}
		if(ans > 0){ x.pb(ans); y.pb(1);}
		//rep(i, 0, x.size()) cout << x[i] << " ";
		//cout << endl;
		//rep(i, 0, y.size()) cout << y[i] << " ";
		//cout << endl;
		ans = 0;
		rep(i, 0, x.size()){
			if(y[i]) ans += x[i];
			else{
				if(i < x.size()-1 && y[i+1]){
					ans += (x[i]*x[i+1]);
					i++;
				}else
					ans += x[i];
			}
			//cout << ans << endl;
		}
		cout << ans << endl;
	}

	return 0;
}
