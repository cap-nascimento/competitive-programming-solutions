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

vi primes;
int arr[MAX];
int twins[MAX];

class SegTree {
private:
    vector<int> st;
    vector<int> a;
    int N;
public:
    SegTree(int _n, int _a[]){
        N = _n;
        rep(i, 0, MAX) a.pb(_a[i]);
        st.assign(4*N, 0);
    }

    void build(int tl, int tr, int v){
        if(tl == tr)
            st[v] = a[tl];
        else{
            int tm = (tr-tl)/2 + tl;
            build(tl, tm, v*2);
            build(tm+1, tr, v*2+1);
            st[v] = st[v*2] + st[v*2+1];
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

void sieve(){
	
	arr[0] = arr[1] = 0;
	for(int i = 2; i*i < MAX; i++){
		if(arr[i]){
			for(int j=i+i;j< MAX;j+=i){
				arr[j] = 0;
			}
		}
	}
	rep(i, 0, MAX)
		if(arr[i]) primes.pb(i);
}

int main() {

	fastio;
	memset(arr, 1, sizeof(arr));
	memset(twins, 0, sizeof(twins));
	sieve();
	
	rep(i, 0, primes.size()){
		size_t pos = lower_bound(primes.begin()+i, primes.end(), primes[i]+2) - primes.begin();
		if(pos < primes.size() && primes[pos]-primes[i] == 2){
			twins[primes[i]] = 1;
			twins[primes[pos]] = 1;
		}
	}

	int n = MAX;
	SegTree st(n, twins);
	st.build(0, n-1, 1);

	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << st.st_sum(0, n-1, min(x, y), max(x, y), 1) << endl;
	}	

	return 0;
}