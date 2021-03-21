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

double pot(int a, int b){
	double ans = .0;
	rep(i, 0, b){
		ans += log2(a);
	}
	return ans;
}

double fat(int a){
	double ans = .0;
	while(a > 0){
		ans += log2(a);
		a--;
	}
	return ans;
}

int main() {

	fastio;

	int n;
	cin >> n;
	int l = 0, p = 0;
	vi res(n);
	rep(i, 0, n){
		string s;
		cin >> s;
		int pos = s.find('^');
		int a = stoi(s.substr(0, pos));
		int b = stoi(s.substr(pos+1, s.size()-pos-1));
		double A = pot(a, b);
		cin >> s;
		a = stoi(s.substr(0, s.size()-1));
		double B = fat(a);
		if(A > B){
			l++;
			res[i] = 1;
		}else{
			p++;
			res[i] = 0;
		}
	}

	if(l == p)
		cout << "A competicao terminou empatada!" << endl;
	else if(l > p)
		cout << "Campeao: Lucas!" << endl;
	else
		cout << "Campeao: Pedro!" << endl;

	rep(i, 0, n){
		cout << "Rodada #" << i+1 << ": " << (res[i] == 0 ? "Pedro" : "Lucas") << " foi o vencedor\n";
	}

	return 0;
}