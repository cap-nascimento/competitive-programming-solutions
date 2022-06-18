/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define vi vector<int>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define MAX 1010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld unsigned long long int
#define endl '\n'
using namespace std;

int main() {

	fastio;
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	sort(a, a+n);
	vi snd;
	bool ans = true;
	rep(i, 0, n){
		if(a[i] <= 8){
			snd.pb(a[i]);
		}else{
			if(snd.size() == 0 || 
			  (snd.size() > 0 && a[i]-snd[snd.size()-1] > 8)){
				ans = false;
				break;
			}else{
				snd.pb(a[i]);
			}
		}
	}
	cout << (ans ? "S" : "N") << endl;
	return 0;
}
