#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Segment {
    ll n, half;
    vector<ll> item;
    Segment(ll n) : n(n) {
        for (half = 1; half < n; half <<= 1);
        item.resize(half * 2);
    }

    void init(vector<ll>& arr) {
        for (ll i = 0; i < n; ++i) 
            item[i + half] = arr[i];
        for (ll i = n; i < half; ++i)
            item[i + half] = 0;
        for (ll i = half - 1; i; --i) 
            item[i] = max(item[i * 2], item[i * 2 + 1]);
    }

    ll sum(ll node, ll ns, ll ne, ll l, ll r) {
        if (l <= ns && ne <= r) return item[node];
        else if (ne < l || r < ns) return 0;
        else {
            ll mid = (ns + ne) / 2;
            return max(sum(2 * node, ns, mid, l, r), sum(2 * node + 1, mid + 1, ne, l, r));
        }
    }

    void update(ll node, ll ns, ll ne, ll idx, ll x) {
        if (ns == ne) item[node] = x;
        else {
            ll mid = (ns + ne) / 2;
            if (idx <= mid) update(node * 2, ns, mid, idx, x);
            else update(node * 2 + 1, mid + 1, ne, idx, x);

            item[node] = max(item[node * 2], item[node * 2 + 1]);
        }
    }
};
