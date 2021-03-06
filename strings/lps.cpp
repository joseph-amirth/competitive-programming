int lps[N];
void constructLps(const string &t) {
    int m = t.length();

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (t[i] == t[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}
