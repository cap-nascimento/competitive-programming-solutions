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

int make_sum(vi x){
	int sum = 0;
	rep(i, 0, x.size()-1) sum += (x[i] - x[i+1]);
	return sum;
}

int main() {

	fastio;

	int n;
	cin >> n;
	int x[n], y[n] = {0};
	rep(i, 0, n) cin >> x[i];
	vector<vi> seqs(n);

	rep(i, 0, n){
		y[i] = 1;
		seqs[i] = {x[i]};
		while(seqs[i].size() < n){
			int curr = seqs[i][seqs[i].size()-1];
			int m = curr, k = 0;
			rep(j, 0, n)if(!y[j]){
				m -= x[j];
				k = j;
				break;
			}
			rep(j, 0, n) if(!y[j]){
				if(curr - x[j] > m){
					m = curr - x[j];
					k = j;
				}
			}
			y[k] = 1;
			seqs[i].pb(x[k]);
		}
		rep(j, 0, n) y[j] = 0;
	}

	int k = 0;
	int sum = make_sum(seqs[0]);
	cout << "-->" << sum << endl;
	rep(i, 1, n){
		int csum = make_sum(seqs[i]);
		cout << csum << endl;
		if(csum > sum){
			sum = csum;
			k = i;
		}		
	}
	
	vector<vi> largest;
	rep(i, 0, n){
		int csum = make_sum(seqs[i]);
		if(csum == sum){
			largest.pb(seqs[i]);
		}
	}

	rep(i, 0, largest.size()){
		rep(j, 0, n) cout << largest[i][j] << " ";
		cout << endl;
	}

	return 0;
}
