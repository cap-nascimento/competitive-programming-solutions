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

class Student{
    public:
        string name;
        int p;
        Student(string name, int p){
            this->name = name;
            this->p = p;
        }
        bool operator<(const Student & other)const{
            if(this->p == other.p)
                return this->name < other.name;
            return this->p > other.p;
        }
};

int main() {

	fastio;

    int n, cas = 1;
    while(cin >> n){
        vector<Student> v;
        rep(i, 1, n+1){
            string name;
            int p;
            cin >> name >> p;
            v.pb({name, p});
        }    

        sort(v.begin(), v.end());
        cout << "Instancia " << cas++ << endl;
        cout << v[n-1].name << "\n\n";
    }


	return 0;
}