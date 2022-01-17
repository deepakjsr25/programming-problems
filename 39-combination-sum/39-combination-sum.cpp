class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> stk; 
        
        function<void(int, int)> fn = [&](int i, int val) {
            if (val == 0) ans.push_back(stk); 
            else if (val > 0) 
                for (int ii = i; ii < candidates.size(); ++ii) {
                    stk.push_back(candidates[ii]); 
                    fn(ii, val - candidates[ii]); 
                    stk.pop_back(); 
                }
        }; 
        
        fn(0, target); 
        return ans; 
    }
};