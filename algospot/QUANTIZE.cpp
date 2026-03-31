#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, S;
int pSum[101];
int pSqSum[101];
int arr[101];
int cache[101][11];

int minError(int lo, int hi) {
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);

    return ret;
}


int quantize(int from, int parts) {
    if (from == N) return 0;
    if (parts == 0) return INT_MAX / 2;

    int& ret = cache[from][parts];
    if (ret != -1) return ret;

    ret = INT_MAX / 2;
    for (int partSize = 1; from + partSize <= N; ++partSize) 
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));

    return ret;
}

void precalc() {
    sort(arr, arr + N);
    memset(cache, -1, sizeof(cache));
    pSum[0] = arr[0];
    pSqSum[0] = arr[0] * arr[0];
    for (int i = 1; i < N; ++i) {
        pSum[i] = arr[i] + pSum[i - 1];
        pSqSum[i] = arr[i] * arr[i] + pSqSum[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> N >> S;

        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        precalc();       

        cout << quantize(0, S) << '\n';
    }
}
