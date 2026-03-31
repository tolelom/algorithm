#include <bits/stdc++.h>
using namespace std;

int n, triangle[101][101];
int cache[101][101];

int path(int y, int x) {
    if (y == n - 1) return triangle[y][x];

    int& ret = cache[y][x];
    if (ret != -1) return ret;

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> n;

        for (int i = 0; i < n; ++i) 
            for (int j = 0; j <= i; ++j)
                cin >> triangle[i][j];
        
        memset(cache, -1 ,sizeof(cache));

        cout << path(0 ,0) << '\n';
    }
}
