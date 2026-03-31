#include <bits/stdc++.h>
using namespace std;

int n, arr[501];
int cache[501];

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = start + 1; next < n; ++next)
        if (arr[start] < arr[next])
            ret = max(ret, lis(next) + 1);

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> n;

        for (int i = 0; i < n; ++i) 
            cin >> arr[i];

        memset(cache, -1, sizeof(cache));

        int ans = 0;
        for (int begin = 0; begin < n; ++begin)
            ans = max(ans, lis(begin));
        
        cout << ans << '\n';
    }
}
