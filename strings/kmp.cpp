template <typename T>
vector<int> KMP(const T& s, int n, const T& t, int m) {
    vector<int> lps; {
        int len = 0, i = 1;
        lps[0] = 0;

        while (i < m) {
            if (t[i] == t[len]) {
                len += 1;
                lps[i] = len;
                i += 1;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i += 1;
            }
        }
    }

    vector<int> match;
    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == t[j]) {
            i += 1;
            j += 1;
        }
        if (j == m) {
            match.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n and s[i] != t[j]) {
            if (j != 0)
                j = lps[j - 1];
            else i += 1;
        }
    }
    return match;
};
