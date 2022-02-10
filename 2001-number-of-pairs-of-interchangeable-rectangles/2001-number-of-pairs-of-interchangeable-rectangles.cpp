class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> h;
        long long ans = 0;
        for(auto &x : rectangles){
            double width = x[0], height = x[1];
            double ratio = width/height;
            ans += h[ratio]++;
        }
        return ans;
    }
};