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

int main() {

	fastio;
    int I, N;
    cin >> I >> N;
    map<char, int> m = {
        mp('D', I), mp('E', I), mp('F', I)
    };

    while(N--){
        char op, j;
        int v;
        cin >> op >> j;
        if(op == 'C'){
            cin >> v;
            m[j] -= v;
        }else if(op == 'V'){
            cin >> v;
            m[j] += v;
        }else{
            char k;
            cin >> k >> v;
            m[j] += v;
            m[k] -= v;
        }
    }

    cout << m['D'] << " " << m['E'] << " " << m['F'] << endl;

	return 0;
}