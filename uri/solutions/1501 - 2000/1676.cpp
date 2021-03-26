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
#define MAX 34000
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

int main()
{

	fastio;
	queue<int> q;
	rep(i, 2, MAX){
		q.push(i);	
	}

	vi v;
	while(!q.empty()){
		int f = q.front();
		//cout << f << endl;
		q.pop();
		v.pb(f);
		int i = 1;
		queue<int> tmp;
		while(!q.empty()){
			if(i%f != 0){
				tmp.push(q.front());
			}
			q.pop();
			i++;
		}
		while(!tmp.empty()){
			q.push(tmp.front());
			tmp.pop();
		}
	}
	//cout << v.size() << endl;
	int n;
	while(cin >> n && n){
		cout << v[n-1] << endl;
	}
	return 0;
}