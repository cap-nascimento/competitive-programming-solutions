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

map<int, char> table;

void pre(){
    table.insert(mp(64, ' '));
    int i = 129;
    for(char c='a';c<='i';c++) table.insert(mp(i++, c));
    i = 145;
    for(char c='j';c<='r';c++) table.insert(mp(i++, c));
    i = 162;
    for(char c='s';c<='z';c++) table.insert(mp(i++, c));
    i = 193;
    for(char c='A';c<='I';c++) table.insert(mp(i++, c));
    i = 209;
    for(char c='J';c<='R';c++) table.insert(mp(i++, c));
    i = 226;
    for(char c='S';c<='Z';c++) table.insert(mp(i++, c));
    i = 240;
    for(char c='0';c<='9';c++) table.insert(mp(i++, c));
}

int otod(string w){
    int ans = 0, d = 1;
    for(int i=w.size()-1;i>=0;i--){
        ans += (w[i]-'0')*d;
        d*=8;
    }
    return ans;
}

int main() {

	fastio;
    pre();
    string l;
    while(getline(cin, l)){
        stringstream ss(l);
        string w;
        while(ss >> w){
            int n = otod(w);
            cout << (table[n]);
        }
        cout << endl;
    }

	return 0;
}