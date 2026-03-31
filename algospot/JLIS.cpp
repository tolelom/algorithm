#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n, m;
int a[101], b[101];
int cache[101][101];

int jlis(int indexA, int indexB) {
    int& ret = cache[indexA + 1][indexB + 1];
    if (ret != -1) return ret;

    ret = 2;
    ll elementA = (indexA == -1 ? LLONG_MIN : a[indexA]);
    ll elementB = (indexB == -1 ? LLONG_MIN : b[indexB]);
    ll maxElement = max(elementA, elementB);

    for (int nextA = indexA + 1; nextA < n; ++nextA)
        if (maxElement < a[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);

    for (int nextB = indexB + 1; nextB < m; ++nextB) 
        if (maxElement < b[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i) 
            cin >> a[i];

        for (int i = 0; i < m; ++i)
            cin >> b[i];

        memset(cache, -1, sizeof(cache));
        
        cout << jlis(-1, -1) - 2 << '\n';
    }
}
