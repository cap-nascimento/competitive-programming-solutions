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

map<char, ii> kb;
void pre(){
	int k = 2, i = 0;
	for(char c='a';c<='z';c++){
		kb[c] = {k, i+1};
		i++;
		if(k == 7 || k == 9){
			if(i%4 == 0){ i=0; k++;}
		}else{
			if(i%3 == 0){ i=0; k++;}
		}
	}
}

void print_letter(char c){
	ii p = kb[c];
	rep(i, 0, p.nd) cout << p.st;
}

int main() {

	fastio;
	int n;
	cin >> n;
	pre();
	cin.ignore();
	while(n--){
		string s;
		getline(cin, s);
		rep(i, 0, s.size()){
			if(s[i] == ' ') cout << "0";
			if(s[i] >= 'A' && s[i] <= 'Z'){
				cout << "#";
				print_letter(s[i]+32);
			}
			if(s[i] >= 'a' && s[i] <= 'z'){
				if(i > 0)
					if(kb[s[i]].st == kb[tolower(s[i-1])].st)
						cout << "*";
				print_letter(s[i]);
			}

		}
		cout << endl;
		/*for(auto x : kb){
			cout << x.st << " -> (" << x.nd.st << ", " << x.nd.nd << ")" << endl;
		}*/
	}

	return 0;
}
