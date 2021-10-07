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

class SegTree {
private:
    vector<int> st;
    vector<int> a;
    int N;
public:
    SegTree(int _n, vector<int> _a){
        N = _n;
        a = _a;
        st.assign(4*N, 0);
    }

    void build(int tl, int tr, int v){
        if(tl == tr)
            st[v] = a[tl];
        else{
            int tm = (tr-tl)/2 + tl;
            build(tl, tm, v*2);
            build(tm+1, tr, v*2+1);
            st[v] = (st[v*2] > st[v*2+1] ? st[v*2] : st[v*2-1]);
        }
    }

    int st_sum(int tl, int tr, int l, int r, int v) {
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return st[v];
        int tm = (tr-tl)/2 + tl;
        return st_sum(tl, tm, l, min(r, tm), v*2) + 
            st_sum(tm+1, tr, max(l, tm+1), r, v*2+1);
    }

};

int main() {

	fastio;

	int n, q;
	cin >> n >> q;
	vi v(n);
	rep(i, 0, n) cin >> v[i];

	SegTree st(n, v);
	st.build(0, n-1, 1);

	int op, a, b, x;
	cin >> op;
	switch(op)
	{
		case 1:
			cin >> a >> b;
			st.update();
		break;
		case 2:
			cin >> a >> b >> x;
			int ans = st.greaters(a, b, x);
		break;
	}

	return 0;
}
