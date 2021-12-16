/*
        Anderson Vieira's solution
        Don't copy this, try for yourself
*/
#include <iostream>
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

        int am, rm, em;
        int av, rv, ev;
        string s;

        cin >> am >> rm >> em;
        cin >> av >> rv >> ev;
        cin.ignore();
        getline(cin, s);

        int tm, tv;
        tm = em*s.size() + 2*am + rm;
        tv = ev*s.size() + 2*av + rv;

        if(tm < tv)
                cout << "Matheus\n";
        else if(tm > tv)
                cout << "Vinicius\n";
        else
                cout << "Empate\n";

        return 0;
}