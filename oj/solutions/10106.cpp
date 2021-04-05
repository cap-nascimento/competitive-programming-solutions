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

string answer(string s){
	string ans = "";
	size_t i = 0;
	while(i < s.size() && s[i] == '0')
		i++;
	if(i == s.size())
		ans = "0";
	else{
		while(i < s.size()){
			ans += s[i++];
		}
	}
	return ans;
}

int main() {

	//fastio;

	string a, b;
	while(cin >> a >> b){
		string s;
		if(b.size() > a.size()){
			s = b;
			b = a;
			a = s;
		}
		vector<string> v;
		for(int i=b.size()-1;i>=0;i--){
			string s = "";
			int next = 0;
			for(int j=a.size()-1;j>=0;j--){
				int m = (b[i]-'0')*(a[j]-'0');
				m += next;
				s += (char)((m%10)+'0');
				if(m > 9){
					if(j == 0)
						s += (char)((m/10)+'0');
					next = m/10;
				}
				else
					next = 0;
			}
			rep(j, 0, s.size()/2) swap(s[j], s[s.size()-j-1]);
			v.pb(s);
		}
		int l = v.size();
		int c = v[0].size() + v[v.size()-1].size();
		int mtx[l][c];
		int k = c-1;
		rep(i, 0, l){
			rep(j, 0, c) mtx[i][j] = 0;
			int x = v[i].size()-1;
			int j = k;
			while(x >= 0){
				mtx[i][j] = (v[i][x])-'0';
				j--; x--;
			}
			k--;
		}
		/*rep(i, 0, l){
			rep(j, 0, c){
				cout << mtx[i][j] << " ";
			}
			cout << endl;
		}*/
		string ans = "";
		int next = 0;
		for(int i=c-1;i>=0;i--){
			int s = 0;
			for(int j=0;j<l;j++){
				s += mtx[j][i];
			}
			s += next;
			ans += (char)((s%10)+'0');
			if(s > 9){
				next = s/10;
			}else{
				next = 0;
			}
		}
		while(next > 0){
			ans += (char)((next%10)+'0');
			next /= 10;
		}
		rep(i, 0, ans.size()/2) swap(ans[i], ans[ans.size()-i-1]);
		cout << answer(ans) << endl;
	}

	return 0;
}