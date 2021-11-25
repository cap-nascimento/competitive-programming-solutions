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
#define MAX 100010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

double dist(ii a, ii b){
	return sqrt((a.st - b.st)*(a.st - b.st) + (a.nd - b.nd)*(a.nd - b.nd));
}

int main() {

	fastio;

	vector<ii> p(5);
	p[0] = {0, 0};
	cin >> p[1].st >> p[1].nd >> p[2].st >> p[2].nd;

	if(y[1] == y[2]){
		x[3] = x[1];
		x[4] = x[2];
		y[3] = y[4] = y[1] + abs(x[1] - x[2]);
	}else if(x[1] == x[2]){
		x[3] = x[4] = x[1] + abs(y[1] - y[2]);
		y[3] = y[1];
		y[4] = y[2];
	}else if(y[1] > y[2]){
		double d = dist({x[1], y[1]}, {x[2], y[2]});
		int l = sqrt((d*d)/2);
		x[3] = x[1];
		y[3] = y[1] - l;
		x[4] = x[2];
		y[4] = y[2] + l;
	}else if(y[1] < p[2].nd){
		double d = dist(p[1], p[2]);
		int l = sqrt((d*d)/2);
		x[3] = x[1];
		y[3] = y[1] + l;
		x[4] = x[2];
		y[4] = y[2] - l;
	}

	cout << x[3] << " " << y[3] << " " << x[4] << " " << y[4] << endl;

	return 0;
}
