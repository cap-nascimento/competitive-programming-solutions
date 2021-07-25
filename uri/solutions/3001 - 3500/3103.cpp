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

	int t;
	cin >> t;
	while(t--)
	{
		string n;
		cin >> n;
		int hash[10] = {0};
		rep(i, 0, n.size()) hash[n[i]-'0']++;
		rep(i, 1, 10){
			if(hash[i] > 0){
				cout << i;
				hash[i]--;
				break;
			}
		}
		while(hash[0] > 0){
			cout << 0;
			hash[0]--;
		}
		rep(i, 0, 10){
			while(hash[i] > 0){
				cout << i;
				hash[i]--;
			}
		}
		cout << endl;
	}

	return 0;
}
