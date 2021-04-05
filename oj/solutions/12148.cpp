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

class Date{
public:
	int d, m, y, c;
	bool operator==(const Date &other){
		if(this->d == other.d && this->m == other.m && this->y == other.y)
			return true;
		return false;
	}
};

void print_date(Date a){
	cout << a.d << "-" << a.m << "-" << a.y << endl;
}

bool is_leap(int year){
	if(year%100 != 0 && (year%400 == 0 || year%4 == 0))
		return true;
	return false;
}

Date next_day(Date a){
	a.d++;
	if(a.m <= 7){
		if(a.m%2 == 0){
			if((a.m == 2 && ((a.d == 29 && !is_leap(a.y)) || a.d == 30)) || (a.d == 31)){
				a.m++; a.d = 1;
			}
		}else{
			if(a.d == 32){
				a.m++; a.d = 1;
			}
		}
	}else{
		if(a.m%2 == 0){
			if(a.d == 32){
				a.m++; a.d = 1;
			}
		}else{
			if(a.d == 31){
				a.m++; a.d = 1;
			}
		}
	}
	if(a.m == 13){
		a.m = 1; a.y++;
	}
	return a;
}

int main() {

	fastio;
	/*Date ini;
	ini.d = 1; ini.m = 1; ini.y = 2000;
	int counter = 0;
	while(counter < 1000){
		print_date(ini);
		ini = next_day(ini);
		counter++;
	}*/

	int n;
	while(cin >> n && n){
		Date days[n];
		int a=0, b=0;
		rep(i, 0, n){
			cin >> days[i].d >> days[i].m >> days[i].y >> days[i].c;
		}
		rep(i, 1, n){
			int j = i;
			if(next_day(days[j-1]) == days[j]){
				vector<Date> v;
				v.pb(days[i-1]);
				while(j < n && next_day(days[j-1]) == days[j]){
					v.pb(days[j]);
					j++;
				}
				i = j-1;				
				if(v.size() > 1){
					a += v.size()-1;
				}
				rep(j, 1, v.size()){
					b += (v[j].c - v[j-1].c);
				}
			}
		}
		cout << a << " " << b << endl;
	}

	return 0;
}