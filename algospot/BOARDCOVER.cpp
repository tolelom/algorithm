#include <bits/stdc++.h>
using namespace std;

// variables
int c;
int h, w;
int board[20][20];

char block[4][3][2] = {
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}}
};


bool inRange(int y, int x) {
    return (0 <= y && y < h && 0 <= x && x < w);
}

bool setBlock(int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + block[type][i][0];
        const int nx = x + block[type][i][1];
        
        if (!inRange(ny, nx)) 
            ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    
    return ok;
}


int fillBoard() {
    int y = -1, x = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == 0) {
                y = i, x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    
    if (y == -1) return 1;
    
    int ret = 0;
    for (int type = 0; type < 4; ++type) {
        if (setBlock(y, x, type, 1))
            ret += fillBoard();
        setBlock(y, x, type, -1);
    }    
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c;
    while (c--) {
        cin >> h >> w;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char temp;
                cin >> temp;
                board[i][j] = (temp == '.' ? 0 : 1);
            }
        }
        
        cout << fillBoard() << '\n';
    }
}
