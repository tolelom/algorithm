#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

class Segment { // segment tree class
    ll n;
	ll half;
	vll item;
public:
	Segment(ll n) : n(n) { // 생성자
		for (half = 1; half < n; half <<= 1); 
		item.resize(half * 2); // n보다 큰 2의 제곱 수 
        
		for (ll i = 0; i < n; ++i) 
			cin >> item[i + half];
            
		for (ll i = n; i < half; ++i)
			item[i + half] = 0;
		for (ll i = half - 1; i; --i)
			item[i] = item[i * 2] + (item[i * 2 + 1]);
	}

	ll sum(ll l, ll r) {
		ll res = 0;
		l += half - 1, r += half - 1;
		while (l <= r) {
			if (l % 2)
				res += item[l++];
			if (!(r % 2))
				res += item[r--];
			l >>= 1; r >>= 1;
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
		for (auto i : item)
			cout << i << ' ';
		cout << '\n';
	}
};

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	segment seg(n);
	for (int i = 0; i < m + k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			seg.update(b, c);
		else if (a == 2)
			cout << seg.sum(b, c) << '\n';
	}
}
