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

double smax(double L, double W){
	double add = L+W;
	double pro = L*W;
	double b = add*4;
	double d = b*b - 48*pro;
	double sq = sqrt(d);
	return (b - sq)/24.0;
}

double smin(double L, double W){
	double add = L+W;
	double pro = L*W;
	double b = add*4;
	double d = b*b - 48*pro;
	double sq = sqrt(d);
	return (b + sq)/24.0;
}

int main() {

	fastio;
	double L, W;
	while(cin >> L >> W){
		if(L == W){
			cout << fixed << setprecision(3) << smax(L, W) << " " 
			<< .0 << " " << smin(L, W) << endl;	
		}else{
			cout << fixed << setprecision(3) << smax(L, W) << " " 
			<< .0 << " " << smin(min(L, W), min(L, W)) << endl;
		}		
	}

	return 0;
}