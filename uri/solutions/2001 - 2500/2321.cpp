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

bool solve(vector<ii> v1, vector<ii> v2){
    int x0 = v2[0].st, y0 = v2[0].nd;
    int x1 = v2[3].st, y1 = v2[3].nd;
    rep(i, 0, 4){
        int x = v1[i].st, y = v1[i].nd;
        if((x >= x0 && x <= x1) && (y >= y0 && y <= y1))
            return true;
    }
    x0 = v1[0].st; y0 = v1[0].nd;
    x1 = v1[3].st; y1 = v1[3].nd;
    rep(i, 0, 4){
        int x = v2[i].st, y = v2[i].nd;
        if((x >= x0 && x <= x1) && (y >= y0 && y <= y1))
            return true;
    }
    vector<ii> l(4);
    l = {
        {0, 2}, {0, 1},
        {1, 3}, {2, 3}
    };
    rep(i, 0, 4){
        int x1 = v1[l[i].st].st, x2 = v1[l[i].nd].st;
        int y1 = v1[l[i].st].nd, y2 = v1[l[i].nd].nd;
        rep(j, 0, 4){
            int x3 = v2[l[j].st].st, x4 = v2[l[j].nd].st;
            int y3 = v2[l[j].st].nd, y4 = v2[l[j].nd].nd;
            // hor
            if(((x1 >= x3 && x1 <= x4) || (x2 >= x3 && x2 <= x4)) && (y1 == y3)) return true;
            // ver
            if(((y1 >= y3 && y1 <= y4) || (y2 >= y3 && y2 <= y4)) && (x1 == x3)) return true;
            // cro
            if((y3 >= y1 && y3 <= y2) && (x1 >= x3 && x1 <= x4)) return true;
        }
    }
    return false;
}

int main() {

	fastio;

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    vector<ii> v1 = {
        mp(x0, y0), mp(x1, y0),
        mp(x0, y1), mp(x1, y1)
    };
    cin >> x0 >> y0 >> x1 >> y1;
    vector<ii> v2 = {
        mp(x0, y0), mp(x1, y0),
        mp(x0, y1), mp(x1, y1)
    };

    //cout << ((a2 < a1) ? 1 : 0) << endl;

    cout << ((solve(v1, v2) || (solve(v2, v1))) ? 1 : 0) << endl;

	return 0;
}