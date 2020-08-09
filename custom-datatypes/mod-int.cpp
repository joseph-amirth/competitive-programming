template <const int M> struct ModInt {
    int val;
    ModInt(ll x = 0): val((x % M + M) % M) {}

    ModInt<M> pow(ll n) const {
        ModInt<M> ans = 1, x = val;
        while (n) {
            if (n & 1) ans *= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }

    ModInt<M> inverse() const { return pow(M - 2); }
    ModInt operator+ (const ModInt<M>& m) { return (val + m.val) % M; }
    ModInt operator- (const ModInt<M>& m) { return ((val - m.val) % M + M) % M; }
    ModInt operator* (const ModInt<M>& m) { return val * (ll) m.val % M; }
    ModInt operator/ (const ModInt<M>& m) { return *this * m.inverse(); }
    ModInt operator+=(const ModInt<M>& m) { return *this = *this + m; }
    ModInt operator-=(const ModInt<M>& m) { return *this = *this - m; }
    ModInt operator*=(const ModInt<M>& m) { return *this = *this * m; }
    ModInt operator/=(const ModInt<M>& m) { return *this = *this / m; }

    friend ostream &operator<<(ostream &os, const ModInt &m) {
        os << m.val;
        return os;
    }
};
