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

set<char> operators = {
	'+', '-', '/', '*'
};

bool is_operator(char c){
	if(operators.find(c) != operators.end())
		return true;
	return false;
}

bool is_operand(char c){
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

int do_operation(int a, int b, char op){
	int ans = 0;
	switch(op){
		case '+': ans = a + b; break;
		case '-': ans = a - b; break;
		case '*': ans = a * b; break;
		case '/': ans = a / b; break;
	}
	return ans;
}

string solve(string e){
	stack<int> st;
	bool f = false;
	for(int i=e.size()-1;i>=0;i--){
		if(is_operand(e[i])){
			st.push(e[i]-'0');
		}
		if(is_operator(e[i])){
			int op1, op2;
			if(!st.empty()){
				op1 = st.top();
				st.pop();
			}else return "Invalid expression.";

			if(!st.empty()){
				op2 = st.top();
				st.pop();
			}else return "Invalid expression.";

			if(op1 == 0 && e[i] == '/'){
				f = true;
				st.push(0);
			}	
			else
				st.push(do_operation(op2, op1, e[i]));
		}
	}
	if(st.size() != 1) return "Invalid expression.";
	if(f) return "Division by zero.";
	return "The answer is " + to_string(st.top()) + ".";
}

int main() {

	fastio;

	string s;
	while(getline(cin, s)){
		string e = "";
		rep(i, 0, s.size()) if(s[i] != ' ') e += s[i];
		cout << solve(e) << endl;
	}

	return 0;
}