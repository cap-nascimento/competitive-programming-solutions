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

int * parse(string date) {
	int * ans = new int[3];
	ans[0] = stoi(date.substr(0, 2));
	ans[1] = stoi(date.substr(3, 2));
	ans[2] = stoi(date.substr(6, 4));
	return ans;
}

int main() {

	fastio;

	string name;
	getline(cin, name);
	string curr, birt;
	getline(cin, curr);
	getline(cin, birt);

	int * d1 = parse(curr);
	int * d2 = parse(birt);
	
	int ans = d1[2] - d2[2];
	if(d1[1] < d2[1] || (d1[1] == d2[1] && d1[0] < d2[0]))
		ans--;

	if(d1[0] == d2[0] && d1[1] == d2[1])
		cout << "Feliz aniversario!" << endl;

	cout << "Voce tem " << ans << " anos " << name << ".\n";

	return 0;
}
