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

typedef struct point{
	double x, y;
}point;

bool inside(point p, pair<point, point> r){
	if(p.x > r.st.x && p.x < r.nd.x && p.y < r.st.y && p.y > r.nd.y)
		return true;
	return false;
}

int main() {

	fastio;

	char c;
	vector<pair<point, point>> ps;
	while(cin >> c){
		if(c == '*')
			break;
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		point p1, p2;
		p1.x = x1; p1.y = y1;
		p2.x = x2; p2.y = y2;
		ps.pb(mp(p1, p2));
	}
	cin.ignore(1);
	string s;
	int cas = 1;
	while(getline(cin, s)){
		if(s.compare("9999.9 9999.9") == 0)
			break;
		stringstream iss(s);
		string w;
		int i = 0;
		double x1, y1;
		while(iss >> w){
			if(!i)
				x1 = stod(w);
			else
				y1 = stod(w);
			i++;
		}
		point p; p.x = x1; p.y = y1;
		int fig = -1;
		rep(i, 0, ps.size()){
			if(inside(p, ps[i])){
				fig = i+1;
				cout << "Point " << cas << " is contained in figure " << fig << endl;
			}
		}
		if(fig == -1)
			cout << "Point " << cas << " is not contained in any figure" << endl;
		cas++;
	}

	return 0;
}