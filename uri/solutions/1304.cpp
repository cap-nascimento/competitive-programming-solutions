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

double solve(string a, string b, double v) {
    int h1 = stoi(a.substr(0, 2));
    int m1 = stoi(a.substr(3, 2));
    int s1 = stoi(a.substr(6, 2));

    int h2 = stoi(b.substr(0, 2));
    int m2 = stoi(b.substr(3, 2));
    int s2 = stoi(b.substr(6, 2));

    double h = ((h1*3600)+(m1*60)+s1) - ((h2*3600)+(m2*60)+s2);
    h /= 3600.0;

    return h*v;
}

int main() {

    fastio;

    string line, h = "00:00:00";
    double v = .0, prev = .0;
    while(getline(cin, line)){
        size_t pos = line.find(' ');
        if(pos != string::npos) {
            prev += solve(line.substr(0, pos), h, v);
            h = line.substr(0, pos);
            v = stod(line.substr(pos+1, line.size()-pos));
        }else{
            cout << line << " ";
            cout << fixed << setprecision(2) << solve(line, h, v)+prev << " km\n";
        }
    }

	return 0;
}