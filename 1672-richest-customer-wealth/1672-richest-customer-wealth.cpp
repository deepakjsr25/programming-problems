class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        for(auto it:accounts){
            maxi=max(maxi,accumulate(it.begin(), it.end(), 0));
        }
        return maxi;
    }
};