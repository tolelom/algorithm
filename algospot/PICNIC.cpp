#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int solve(vector<vector<bool>>& friends, vector<bool>& sel) {
    int one = -1;
    for (int i = 0; i < sel.size(); ++i) {
        if (!sel[i]) {
            one = i;
            break;
        }
    }

    if (one == -1) return 1;

    int ret = 0;
    for (int two = one + 1; two < sel.size(); ++two) {
        if (!friends[one][two] || sel[two]) continue;
        
        sel[one] = sel[two] = true;
        ret += solve(friends, sel);
        sel[one] = sel[two] = false;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    
    while (c--) {
        int n, m;
        cin >> n >> m;

        vector<vector<bool>> friends(n, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            friends[a][b] = friends[b][a] = true;
        }

        vector<bool> sel(n, false);
        int ans = solve(friends, sel);

        cout << ans << '\n';
    }

}
