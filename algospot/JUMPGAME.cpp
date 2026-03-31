#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int cache[100][100];
int n; 

bool jump(int y, int x) {
    if (n <= y || n <= x) return false;
    if (y == n - 1 && x == n - 1) return true;

    int& ret = cache[y][x];
    if (ret != - 1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while(c--) {
        memset(board, 0, sizeof(board));
        memset(cashe, -1, sizeof(cashe));
        cin >> n;

        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                cin >> board[i][j];

        if (jump(0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
