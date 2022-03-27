class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[j][i]==0){
                    nums.push_back(j);
                }
            }
        }
    
        vector<int> ct(m,-1);    
        for(int i=0;i<nums.size() && k;i++){
            if(ct[nums[i]]==-1){
                ct[nums[i]]=1;
                k--;
                ans.push_back(nums[i]);
            }
        }
        
        int i=0;
        while(k && i<m){
            if(ct[i]!=1){
                ans.push_back(i);
                k--;
            }
            i++;
        }
        
        return ans;
    }
};