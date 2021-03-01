/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <stdio.h>
#define MAX 100010
int v[MAX];
int L[MAX];
int contains(int x){
	while(x > 0){
		if(x%10 == 7)
			return 1;
		x /= 10;
	}
	return 0;
}
int solve(int n, int m, int k){
	int a = (n-m)*2;
	int b = (m-1)*2;
	int l = 1, i = 0;
	while(i < MAX){
		L[i] = l;
		v[i++] = m;
		if(l)
			m += a;
		else
			m += b;
		l = 1-l;
	}
	for(i=0;i<MAX;i++){
		if(v[i]%7 == 0 || contains(v[i]))
			break;
	}
	if(i == MAX) 
		return -1;
	int val = n - a/2;
	l = 1;
	i = 0;
	while(1){
		if(val%7 == 0 || contains(val)){
			i++;
			if(i == k) return val;
		}
		if(a == 0){
			val += b;
		}else if(b == 0){
			val += a;
		}else{
			if(l)
				val += a;
			else
				val += b;
			l = 1-l;
		}
	}
	return val;
}

int main(){

	int n, m, k;
	
	while(scanf("%d %d %d", &n, &m, &k)){
		if(n == 0 && m == 0 && k == 0)
			break;
		printf("%d\n", solve(n, m, k));
	}

	return 0;
}