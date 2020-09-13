ll power(ll base, ll exponent, ll mod) {
    ll result = 1;
    while (exponent) {
        if (exponent % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}
