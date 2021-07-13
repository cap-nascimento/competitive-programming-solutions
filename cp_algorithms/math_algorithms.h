#ifndef MATHALGORITHMS_H_DEFINED
#define MATHALGORITHMS_H_DEFINED

/*Modular inverse tools*/
/**
 * GCD Extended
 * */
ll gcdx(ll a, ll b, ll *x, ll *y){
 if(a == 0){*x = 0; *y = 1; return b;}
 ll x1, y1;
 ll gcd = gcdx(b%a, a, &x1, &y1);
 *x = y1 - (b/a)*x1;
 *y = x1;
 return gcd;
}

/**
 * Modular inverse
 * */
ll modular_inverse(ll b, ll m){
 ll x, y;
 ll g = gcdx(b, m, &x, &y);
 if(g != 1) return -1;
 return (x%m+m)%m;
}

/**
 * Modular division
 * */
ll modular_division(ll a, ll b, ll m){
 a = a%m;
 ll inv = modular_inverse(b, m);
 return (inv*a)%m;
}

#endif // MATHALGORITHMS_H_DEFINED
