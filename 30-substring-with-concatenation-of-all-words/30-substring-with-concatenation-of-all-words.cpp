class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int count = words.size();
    vector<int> ans;
    int wcnt = words.size();
    int wlen = words[0].length();

    unordered_map<string, int> m;
    // unordered_map<string, int> m2;
    // m[0] = 6;

    for (auto it : words)
    {
        m[it]++;
        // m2[it]++;
    }

    int start, idx, next;
    int ssize = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        start = idx = i;
        int tot = 0;
        unordered_map<string, int> cur;
        while (start + wlen * wcnt <= ssize)
        {
            string w = s.substr(idx, wlen);
            cur[w]++;
            tot++;
            if (cur[w] > m[w])
                break;
            else if (tot == wcnt)
            {
                ans.push_back(start);
                break;
            }
            idx = idx + wlen;
        }
    }
        return ans;
    }
};