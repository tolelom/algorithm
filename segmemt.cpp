class Segment {
public:
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
            item[i + half] = 1'000'000'000;
        for (ll i = half - 1; i; --i) 
            item[i] = min(item[i * 2], item[i * 2 + 1]);
    }

    ll query(ll node, ll start, ll end, ll left, ll right) {
        if (left <= start && end <= right) return item[node];
        else if (end < left || right < start) return 1'000'000'000;
        else {
            ll mid = (start + end) / 2;
            return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, l, r));
        }
    }

    void update(ll node, ll start, ll end, ll idx, ll x) {
        if (start == end) item[node] = x;
        else {
            ll mid = (start + end) / 2;
            if (idx <= mid) update(node * 2, start, mid, idx, x);
            else update(node * 2 + 1, mid + 1, end, idx, x);

            item[node] = min(item[node * 2], item[node * 2 + 1]);
        }
    }
};
