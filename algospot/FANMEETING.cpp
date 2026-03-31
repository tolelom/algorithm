// 결국 실패했다
// 시간 제한도 이상한 거 같고 
// addTo 함수 같은데서 세그먼트 오류가 발생하는 듯 하다
// normalize는 기본!

#include <bits/stdc++.h>
using namespace std;

void normalize(vector<int>& num) {
    num.push_back(0);

    for (int i = 0; i < num.size(); ++i) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        } else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) 
        for (int j = 0; j < b.size(); ++j)
            c[i + j] += (a[i] * b[j]);

    //normalize(c);
    return c;
}


void addTo(vector<int>& a, const vector<int>& b, int k) {
    int newsize = a.size() < b.size() + k ? b.size() + k : a.size();
    //while (a.size() != newsize) a.push_back(0);
    for (int i = k; i < newsize; i++) {
        a[i] += + b[i - k];
    }
    //normalize(a);
}
 
void subFrom(vector<int> &a, const vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    //normalize(a);
}
 

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);

    if (an == 0 || bn == 0) return vector<int>();

    if (an <= 50) return multiply(a, b);
    
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, b1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);

    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}


int hugs(const string& members, const string& fans) {
    int n = members.size(), m = fans.size();
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) a[i] = (members[i] == 'M');
    for (int i = 0; i < m; ++i) b[i] = (fans[i] == 'M');

    vector<int> c = karatsuba(a, b);
    int allHugs = 0;
    for (int i = n - 1; i < m; ++i) {
        if (c[i] == 0)
            ++allHugs;
    }

    return allHugs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while(c--) {
        string members, fans;
        cin >> members >> fans;
        
        reverse(fans.begin(), fans.end());
        cout << hugs(members, fans) << '\n';
    }
}
