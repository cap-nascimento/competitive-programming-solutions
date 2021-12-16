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
#define MAX 110
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;

	string n;
	cin >> n;
	rep(i, 0, n.size()){	
		int j = i;
		if(n[i] == '3' || n[i] == '5'){
			while(j > 0){
				if(n[j-1] - n[j] == 2){
					swap(n[j-1], n[j]);
					j--;
				}else break;
			}
		}
	}
	int pos = -1;
	rep(i, 0, n.size()) {
		if(n[i] == '7'){ pos = i; break;}
	}
	if(pos!=-1){
		rep(i, pos+1, n.size()){
			if(n[i] == '5'){
				int j = i;
				while(j > pos){
					swap(n[j], n[j-1]);
					j--;
				}
				pos++;
			}
		}
	}
	cout << n << endl;

	return 0;
}
