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
#define PI 3.14159265359
using namespace std;

int main() {

	fastio;

	int n, y;
	while(cin >> n >> y)
	{
		cin.ignore();
		set<string> c;
		int ans = 0;
		rep(i, 0, n)
		{
			string s,w;
			getline(cin, s);
			stringstream ss(s);
			string a = "";
			while(ss >> w)
			{
				a += w[0];
			}
			a += to_string(y);
			if(c.find(a) == c.end())
				c.insert(a);
			else
				ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
