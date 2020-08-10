struct Fraction {
    struct Fraction {
    ll num, dem;
    explicit Fraction(ll num = 0, ll dem = 1) {
        if (dem < 0) {
            dem *= -1;
            num *= -1;
        }
        ll g = __gcd(num, dem);
        this->num = num / g;
        this->dem = dem / g;
    }

    Fraction operator-() const {
        Fraction res = *this;
        res.num = -res.num;
        return res;
    }
    Fraction operator+ (const Fraction& rhs) {
        ll temp1 = num * rhs.dem + rhs.num * dem, temp2 = dem * rhs.dem;
        ll g = __gcd(temp1, temp2);
        return Fraction(temp1 / g, temp2 / g);
    }
    Fraction operator- (const Fraction& rhs) {
        ll temp1 = num * rhs.dem - rhs.num * dem, temp2 = dem * rhs.dem;
        ll g = __gcd(temp1, temp2);
        return Fraction(temp1 / g, temp2 / g);
    }
    Fraction operator* (const Fraction& rhs) {
        ll temp1 = num * rhs.num, temp2 = dem * rhs.dem;
        ll g = __gcd(temp1, temp2);
        return Fraction(temp1 / g, temp2 / g);
    }
    Fraction operator/ (const Fraction& rhs) {
        ll temp1 = num * rhs.dem, temp2 = dem * rhs.num;
        ll g = __gcd(temp1, temp2);
        return Fraction(temp1 / g, temp2 / g);
    }
    Fraction operator+=(const Fraction& rhs) { return *this = *this + rhs; }
    Fraction operator-=(const Fraction& rhs) { return *this = *this - rhs; }
    Fraction operator*=(const Fraction& rhs) { return *this = *this * rhs; }
    Fraction operator/=(const Fraction& rhs) { return *this = *this / rhs; }

    bool operator==(const Fraction& rhs) const { return tie(num, dem) == tie(rhs.num, rhs.dem); }
    bool operator!=(const Fraction& rhs) const { return !(*this == rhs); }
    bool operator< (const Fraction& rhs) const { return num * rhs.dem < rhs.num * dem; }
    bool operator> (const Fraction& rhs) const { return rhs < *this; }
    bool operator<=(const Fraction& rhs) const { return !(*this > rhs);}
    bool operator>=(const Fraction& rhs) const { return !(*this < rhs); }
};
};
