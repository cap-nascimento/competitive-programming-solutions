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

map<int, vi> n1;
string mtx[7][12] = {
	"C", "C#",  "D", "D#",  "E",  "F", "F#",  "G", "G#",  "A", "A#",  "B",
	"D", "D#",  "E",  "F", "F#",  "G", "G#",  "A", "A#",  "B",  "C", "C#",
	"E",  "F", "F#",  "G", "G#",  "A", "A#",  "B",  "C", "C#",  "D", "D#",
	"F", "F#",  "G", "G#",  "A", "A#",  "B",  "C", "C#",  "D", "D#",  "E",
	"G", "G#",  "A", "A#",  "B",  "C", "C#",  "D", "D#",  "E",  "F", "F#",
	"A", "A#",  "B",  "C", "C#",  "D", "D#",  "E",  "F", "F#",  "G", "G#",
	"B",  "C",  "C#", "D", "D#",  "E",  "F", "F#",  "G", "G#",  "A", "A#"};
map<string, int> n2 = {
	mp("A", 9), mp("A#", 10), mp("Bb", 10), mp("B", 11), mp("Cb", 11),
	mp("C", 0), mp("B#", 0), mp("C#", 1), mp("Db", 1), mp("D", 2),
	mp("D#", 3), mp("Eb", 3), mp("E", 4), mp("Fb", 4), mp("F", 5), mp("E#", 5),
	mp("F#", 6), mp("Gb", 6), mp("G", 7), mp("G#", 8), mp("Ab", 8)};
void pre(){rep(i, 0, 12) rep(j, 0, 7) n1[i].pb(n2[mtx[j][i]]);}

int m, t;
vi so(MAX), sn(MAX);

vi lps(){
	int len = 0;
	vi res(t);
	res[0] = 0;
	int i = 1;
	while(i < t){
		if(sn[i] == sn[len]){
			len++;
			res[i] = len;
			i++;
		}else{
			if(len != 0)
				len = res[len-1];
			else{
				res[i] = 0;
				i++;
			}
		}
	}
	return res;
}

bool kmp(){
	vi arr = lps();
	int i = 0, j = 0;
	while(i < m){
		if(sn[j] == so[i]){
			j++; i++;
		}
		if(j == t)
			return true;
		else if(i < m && sn[j] != so[i]){
			if(j != 0)
				j = arr[j-1];
			else
				i++;
		}
	}
	return false;
}

bool solve(){
	int tmp[m];
	rep(i, 0, m) tmp[i] = so[i];
	/*rep(i, 0, t) cout << sn[i] << " ";
	cout << endl;*/
	rep(i, 0, 12){
		rep(j, 0, m) so[j] = (tmp[j]+i)%12;
		/*rep(j, 0, m) cout << so[j] << " ";
		cout << endl;*/
		if(kmp()) return true;
	}
	return false;
}

int main() {

	fastio;

	pre();
	while(cin >> m >> t && (m && t)){
		string s;
		rep(i, 0, m){cin >> s; so[i] = n2[s];}
		rep(i, 0, t){cin >> s; sn[i] = n2[s];}

		if(solve())
			cout << "S\n";
		else
			cout << "N\n";

	}

	return 0;
}
