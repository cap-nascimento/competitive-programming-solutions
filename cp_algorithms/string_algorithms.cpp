/*
    Code to implement various algorithms to use on strings.
*/
#include <bits/stdc++.h>
using namespace std;

/*
****************************************
*   Common classes to the algorithms   *
****************************************
*/

/*
    text -> the algorithm runs on it
	pattern -> to use on pattern search / matching
	M -> text size
	N -> pattern size
*/
class StringSet{
	public:
		string text;
		string pattern;
		size_t M, N;
		StringSet(string);
		StringSet(string, string);
};

StringSet::StringSet(string text){
	this->text = text;
	this->M = text.size();
}

StringSet::StringSet(string text, string pattern){
	this->text = text;
	this->pattern = pattern;
	this->M = text.size();
	this->N = pattern.size();
}

/*
****************************************
*             Algorithms               *
****************************************
*/

/*
*
* Knuth-Morris-Pratt Algorithm
* Source: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*
*/
void compute_longest_prefix_suffix(string pattern, int N, vector<int>& array);
void KMP(StringSet base){ 
	vector<int> longest_prefix_suffix(base.N);
	compute_longest_prefix_suffix(base.pattern, base.N, longest_prefix_suffix);
	size_t i = 0, j = 0;
	while(i < base.M){ 
		if(base.pattern[j] == base.text[i]){ 
			j++; i++; 
		} 
		if(j == base.N){ 
			cout << "Found pattern at index " << i-j << endl;
			j = longest_prefix_suffix[j - 1]; 
		}else if(i < base.M && base.pattern[j] != base.text[i]){ 
			if(j != 0) 
				j = longest_prefix_suffix[j - 1]; 
			else
				i++; 
		} 
	} 
} 

/*
	Auxiliary function to KMP
	pattern -> text to be found
	N -> pattern size
	array -> resulting array
*/
void compute_longest_prefix_suffix(string pattern, int N, vector<int>& array){ 
	int len = 0; 
	array[0] = 0;
	int i = 1; 
	while(i < N){ 
		if(pattern[i] == pattern[len]){ 
			len++; 
			array[i] = len; 
			i++; 
		}else{
			if(len != 0)
				len = array[len - 1];
			else{ 
				array[i] = 0; 
				i++; 
			} 
		} 
	} 
}

int main(){ 
	
	string text = "THIS IS A TEST TEXT";
	string pattern = "TEST";
	StringSet base(text, pattern);

	// KMP example
	cout << "KMP example (find " << base.pattern << " on "<< base.text <<"):\n";
	KMP(base);

	return 0; 
} 

