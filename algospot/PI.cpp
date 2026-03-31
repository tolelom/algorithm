#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int cache[10001];

int classify(int a, int b) {
    string M = s.substr(a, b - a + 1);
    
    if (M == string(M.size(), M[0])) return 1;
    
    bool progressive = true;
    for (int i = 0; i < M.size() - 1; ++i) {
        if (M[i + 1] - M[i] != M[1] - M[0]) 
            progressive = false;
    }
    if (progressive && abs(M[1] - M[0]) == 1) return 2;


    bool alternating = true;
    for (int i = 0; i < M.size(); ++i) {
        if (M[i] != M[i % 2])
            alternating = false;
    }
    if (alternating) return 4;

    if (progressive) return 5;

    return 10; 
}

int solve(int begin = 0) {
    if (begin == s.size()) return 0;

    int& ret = cache[begin];
    if (ret != -1) return ret;

    ret = INT_MAX / 2;
    for (int i = 3; i <= 5; ++i) {
        if (begin + i <= s.size())
            ret = min(ret, solve(begin + i) + classify(begin, begin + i - 1));
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> s;
        memset(cache, -1, sizeof(cache));

        cout << solve() << '\n';
    }
}
