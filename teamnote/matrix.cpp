class matrix {
   public:
    ll size;
    ll mod = 1'000'000'007; // modular는 선택입니다만.. 지금은 잠시만 1000
    vector<vector<ll>> item;

    matrix(ll n = 0) : size(n) {
        item.resize(n);
        for (int i = 0; i < n; ++i) item[i].resize(n);
    }

    matrix operator*(const matrix other) {
        matrix temp(size);
        for (int k = 0; k < size; ++k) 
            for (int i = 0; i < size; ++i) 
                for (int j = 0; j < size; ++j) {
                    temp.item[i][j] += item[i][k] * other.item[k][j]; // 아래 줄에서 오버플로우 
                    temp.item[i][j] = (temp.item[i][j] + mod) % mod; // item[i][j] 값이 음수이면 mod해도 음수이므로 + mod
                }
        return temp;
    }

    matrix identity() {
        matrix result(size);
        for (int i = 0; i < size; ++i) result.item[i][i] = 1;
        return result;
    }

    matrix exponent(ll times) {
        matrix result, temp;

        result = matrix(size).identity();
        temp = *this;

        while (times) {
            if (times % 2) 
                result = result * temp;
            times /= 2;
            temp = temp * temp;
        } 
        return result;
    }
};
