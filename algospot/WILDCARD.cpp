#include <bits/stdc++.h>
using namespace std;

string w, s;
priority_queue<string, vector<string>, greater<string>> pq;
int cache[101][101];

bool match(int wPos, int sPos) {
    int& ret = cache[wPos][sPos];
    if (ret != -1) return ret;

    while (sPos < s.size() && wPos < w.size() && (w[wPos] == '?' || w[wPos] == s[sPos])) {
        return ret = match(wPos + 1, sPos + 1);
    }

    if (wPos == w.size()) return ret = (sPos == s.size());

    if (w[wPos] == '*') 
        if (match(wPos + 1, sPos) || (sPos < s.size() && match(wPos, sPos + 1)))
            return ret = 1;
    
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> w;

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> s;
            memset(cashe, -1, sizeof(cashe));
            if (match(0, 0)) pq.push(s);
        }


        while (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}
