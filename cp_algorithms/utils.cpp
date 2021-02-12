/*
    Code to implement segment tree (sum queries)
    Source: https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-3
*/

#include <bits/stdc++.h>
using namespace std;

class SegTree {
private:
    vector<int> st;
    vector<int> a;
    int N;
public:
    SegTree(int _n, vector<int> _a){
        N = _n;
        a = _a;
        st.assign(4*N, 0);
    }

    void build(int tl, int tr, int v){
        if(tl == tr)
            st[v] = a[tl];
        else{
            int tm = (tr-tl)/2 + tl;
            build(tl, tm, v*2);
            build(tm+1, tr, v*2+1);
            st[v] = st[v*2] + st[v*2+1];
        }
    }

    int st_sum(int tl, int tr, int l, int r, int v) {
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return st[v];
        int tm = (tr-tl)/2 + tl;
        return st_sum(tl, tm, l, min(r, tm), v*2) + 
            st_sum(tm+1, tr, max(l, tm+1), r, v*2+1);
    }

};

int main()
{

    int n = 10;
    SegTree a(n, {0, 1, 1, 1, 0, 1, 1, 0, 1, 0});

    a.build(0, n-1, 1);

    vector<pair<int, int>> queries = {
        make_pair(0, 9),
        make_pair(1, 3),
        make_pair(3, 6),
        make_pair(2, 8)
    };

    for(int i=0;i<queries.size();i++){
        cout << a.st_sum(0, n-1, queries[i].first, queries[i].second, 1) << endl;
    }

    return 0;
}