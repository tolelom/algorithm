#include <bits/stdc++.h>
using namespace std;


string solve(const string& s, string::iterator& it) {
    char head = *(it++);
    
    if (head == 'b' || head == 'w')
        return string(1, head);
    
    string sub[4];
    for (int i = 0; i < 4; ++i)
        sub[i] = solve(s, it);

    return string("x") + sub[2] + sub[3] + sub[0] + sub[1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
     
    while (c--) {
        string s;
        cin >> s;
        string::iterator it = s.begin();

        cout << solve(s, it) << '\n';
    }
}
