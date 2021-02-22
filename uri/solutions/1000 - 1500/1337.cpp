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

void print_ans(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
}

int main() {

	fastio;

    int a, b, c;
    while(cin >> a >> b >> c && (a && b && c)){
        int v[3] = {a, b, c};
        sort(v, v+3);
        a = v[0]; b = v[1]; c = v[2];
        if(a == b && b == c){
            if(a == 13) cout << "*\n";
            else print_ans(a+1, a+1, a+1);
        }else if(a == b || b == c){
            if(a == b){
                if(c == 13) print_ans(1, a+1, a+1);
                else print_ans(a, a, c+1);
            }else{
                if(b-a >= 2) print_ans(a+1, b, b);
                else{
                    if(a+2 > 13) print_ans(1, 1, 1);
                    else print_ans(b, b, b+1);
                }
            }
        }else{
            print_ans(1, 1, 2);
        }
    }

	return 0;
}