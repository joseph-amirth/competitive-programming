int lps[N], f[26][N];

void constructLps(const string &pat) {
    int m = pat.length();

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
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

void constructAuto(const string &s) {
    constructLps(s);
    for (int j = 0; j < s.length(); j++) {
        for (int i = 0; i < 26; i++) {
            if (i == s[j] - 'a' or j == 0)
                f[i][j] = j;
            else f[i][j] = f[i][lps[j-1]];
        }
    }
}
