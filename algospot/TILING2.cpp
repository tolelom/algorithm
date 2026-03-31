#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
int n;
int cache[101];

int solve(int size) {
    if (size <= 1) return 1;

    int& ret = cache[size];
    if (ret != -1) return ret;

    ret = (solve(size - 1) + solve(size - 2)) % mod;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;


    while (testCase--) {
        cin >> n;

        memset(cache, -1, sizeof(cache));
        cout << solve(n) << '\n';

    }
}
