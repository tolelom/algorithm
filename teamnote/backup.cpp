#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans =  (v.back() % 12) ? (v.back() / 12 + 1) * 12 : (v.back() / 12) * 12;
    ans -= (v.front() / 12) * 12;
    K -= 2; // 최초 과거로 돌아가기 && 마지막에 현재로 돌아오기
    

}
