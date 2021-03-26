#include "data_structures.h"

int main()
{

    // Test segment tree (sum queries)
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