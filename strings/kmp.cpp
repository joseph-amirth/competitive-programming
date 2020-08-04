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

vector<int> kmp(const string &s, const string &t) {
    constructLps(t);
    vector<int> occur;

    int n = s.length(), m = t.length(), i = 0, j = 0;

    while (i < n) {
        if (s[i] == t[j]) {
            i += 1;
            j += 1;
        }

        if (j == m) {
            occur.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n and s[i] != t[j]) {
            if (j != 0)
                j = lps[j-1];
            else i += 1;
        }
    }
    return occur;
}
