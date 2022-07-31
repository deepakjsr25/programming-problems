class Solution {
public:
    int maximumGroups(vector<int>& grades) {
    int l = 1, r = 446, n = grades.size();
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (m * (m + 1) / 2 <= n)
            l = m;
        else
            r = m - 1;
    }
        return l;
    }
};