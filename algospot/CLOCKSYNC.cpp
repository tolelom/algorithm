#include <bits/stdc++.h>
using namespace std;

const int INF = 9999;
const vector<vector<int>> btn = {
    {0, 1, 2}, 
    {3, 7, 9, 11}, 
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};


bool checkAllClockZero(const vector<int>& clock) {
    for (auto it : clock) {
        if (it != 0) return false;
    }
    return true;
}

void pressBtn(vector<int>& clock, int n) {
    for (auto it : btn[n]) 
        clock[it] = (clock[it] + 3) % 12;
}


int solve(vector<int> clock, int n) {
    if (n == 10) return checkAllClockZero(clock) ? 0 : INF;

    int ret = INF;
    for (int i = 0; i < 4; ++i) {
        ret = min(ret, i + solve(clock, n + 1));
        pressBtn(clock, n);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
     
    while (c--) {
        vector<int> clock(16);
        for (int i = 0; i < 16; ++i) {
            cin >> clock[i];
            clock[i] %= 12;
        }

        int ans = solve(clock, 0);

        cout << ((INF <= ans) ? -1 : ans) << '\n';
    }
}
