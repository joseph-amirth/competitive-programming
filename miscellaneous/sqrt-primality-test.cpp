bool isPrime(int x) {
    if (x == 1)
        return false;

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
