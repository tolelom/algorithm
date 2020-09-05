#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

class Segment {  // segment tree class
    ll n;
    ll half;
    vll item;

   public:
    Segment(ll n) : n(n) {  // 생성자
        for (half = 1; half < n; half <<= 1)
            ;
        item.resize(half * 2);  // n보다 큰 2의 제곱 수
    }

    void init(ll n) { // 초기화 함수
        fill(item.begin(), item.end(), 0);
        for (ll i = 0; i < n; ++i)  // 0 ~ n-1까지
            cin >> item[i + half];

        for (ll i = half - 1; i; --i)  // 조건을 i로 하는 흑마법
            item[i] = item[i * 2] + (item[i * 2 + 1]);
    }

    ll sum(ll left, ll right) {
        ll res = 0;
        left += half - 1, right += half - 1;
        while (left <= right) {
            if (left % 2) res += item[l++];
            if (!(right % 2)) res += item[r--];
            left >>= 1;
            right >>= 1;
        }
        return res;
    }
    void update(ll idx, ll x) {
        idx += half - 1;
        item[idx] = x;
        idx >>= 1;
        while (idx) {
            item[idx] = item[idx * 2] + item[idx * 2 + 1];
            idx >>= 1;
        }
    }

    void print() {
        for (auto i : item) cout << i << ' ';
        cout << '\n';
    }
};
