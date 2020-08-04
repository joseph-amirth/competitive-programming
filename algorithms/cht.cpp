using point = pair<int, int>;

class ConvexHullTrick {
public:
    vector<point> lines;

    bool f1(point l1, point l2, point l3) {
        return (ll)(l1.second - l2.second) * (l3.first - l1.first) >= (ll)(l1.second - l3.second) * (l2.first - l1.first);
    }
    bool f2(point l1, point l2, ld x) {
        return (l1.second - l2.second) <= (ll)(l2.first - l1.first) * x;
    }

    void add(int m, int c) {
        point nw(m, c);
        while (lines.size() > 1 and f1(lines[lines.size() - 2], lines[lines.size() - 1], nw)) {
            lines.pop_back();
        }
        lines.push_back(nw);
    }

    ld get(ld x) {
        int lo = 0, hi = lines.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (f2(lines[mid - 1], lines[mid], x))
                lo = mid;
            else hi = mid - 1;
        }
        return lines[lo].first * x + lines[lo].second;
    }
};
