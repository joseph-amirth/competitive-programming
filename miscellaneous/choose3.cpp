ll fact[N];
ll choose(int n, int k) {
    ll num = fact[n];
    ll dem = fact[k] * fact[n - k] % mod;
    return num * modinv(dem) % mod; //num * modular inverse of dem
}
