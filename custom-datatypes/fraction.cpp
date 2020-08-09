struct Fraction { //not fully functional (arithmetic operations haven't been implemented)
    int num, dem;
    explicit Fraction(int num = 0, int dem = 1) {
        int g = __gcd(num, dem);
        this->num = num / g;
        this->dem = dem / g;
    }

    bool operator==(const Fraction& rhs) const {
        return tie(num, dem) == tie(rhs.num, rhs.dem);
    }
    bool operator!=(const Fraction& rhs) const {
        return !(*this == rhs);
    }
    bool operator<(const Fraction& rhs) const {
        return (ll)num * rhs.dem < (ll)rhs.num * dem;
    }
    bool operator>(const Fraction& rhs) const {
        return rhs < *this;
    }
    bool operator<=(const Fraction& rhs) const {
        return !(*this > rhs);
    }
    bool operator>=(const Fraction& rhs) const {
        return !(*this < rhs);
    }
};
