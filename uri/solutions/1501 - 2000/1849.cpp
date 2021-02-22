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
	int l1, c1, l2, c2;
	cin >> l1 >> c1 >> l2 >> c2;

	vector<int> a;
	a.pb(min(l1, c1)*min(l1, c1));
	a.pb(min(l2, c2)*min(l2, c2));
	if(c1+c2 >= min(l1, l2)) a.pb(min(l1, l2)*min(l1, l2));
	else a.pb((c1+c2)*(c1+c2));
	if(c1+l2 >= min(l1, c2)) a.pb(min(l1, c2)*min(l1, c2));
	else a.pb((c1+l2)*(c1+l2));
	if(c2+l1 >= min(c1, l2)) a.pb(min(c1, l2)*min(c1, l2));
	else a.pb((c2+l1)*(c2+l1));
	if(l1+l2 >= min(c1, c2)) a.pb(min(c1, c2)*min(c1, c2));
	else a.pb((l1+l2)*(l1+l2));

	cout << *max_element(a.begin(), a.end()) << endl;

	return 0;
}