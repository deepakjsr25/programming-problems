class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        int sum=0;
        for(auto it:accounts){
            sum=0;
            sum=accumulate(it.begin(), it.end(), 0);
            maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};