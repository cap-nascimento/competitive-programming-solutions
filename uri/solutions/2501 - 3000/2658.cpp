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

ii t[4*MAX];
bool lazy[4*MAX];

void push(int v)
{
	t[v*2].st = (t[v*2].st + lazy[v])%9;
	lazy[v*2] = (lazy[v*2] + lazy[v])%9;
	t[v*2+1].st = (t[v*2+1].st + lazy[v])%9;
	lazy[v*2+1] = (lazy[v*2+1] + lazy[v])%9;
	lazy[v] = 0;
}

ii combine(ii a, ii b)
{
	if(a.nd == b.nd){
		if(a.st > b.st)
			return a;
		else if(a.st == b.st)
			return mp(a.st, a.nd + b.nd);
		return b;
	}
	if(a.nd > b.nd){
		return a;
	}
	return b;
}

void build(int a[], int v, int tl, int tr)
{
	if(tl == tr)
		t[v] = mp(a[tl], 1);
	else{
		int tm = (tl + tr)/2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

ii get_max(int v, int tl, int tr, int l, int r)
{
	if(l > r)
		return mp(-oo, 0);
	if(l == tl && r == tr)
		return t[v];
	int tm = (tl + tr)/2;
	return combine(get_max(v*2, tl, tm, l, min(r, tm)),
		       get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int l, int r, int add)
{
	if(l > r)
		return;
	if(l == tl && r == tr){
		t[v].st = (t[v].st + add)%9;
		lazy[v] = (lazy[v] + add)%9;	
	} else {
		push(v);
		int tm = (tl + tr)/2;
		update(v*2, tl, tm, l, min(r, tm), add);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
	/*if(tl == tr){
		t[v] = mp(new_val, 1);	
	}else{
		int tm = (tl + tr)/2;
		if(pos <= tm)
			update(v*2, tl, tm, pos, new_val);
		else
			update(v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine(t[v*2], t[v*2+1]);
	}*/
}

int main() {

	fastio;

	int n, q;
	cin >> n >> q;
	int a[n];
	rep(i, 0, n) a[i] = 1;
	build(a, 1, 0, n-1);
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		ii res = get_max(1, 0, n-1, a, b);
		update(1, 0, 6, a, b, res.st);
	}
	rep(i, 0, n)
		cout << a[i] << endl;

	return 0;
}
