class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix_sum(n);
        vector<int> ans;
        
        prefix_sum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix_sum[i]=prefix_sum[i-1]^arr[i];
        }
        
        for(auto it: queries){
            if(it[0]==0){
                ans.push_back(prefix_sum[it[1]]);
            }
            else{
                ans.push_back(prefix_sum[it[0]-1]^prefix_sum[it[1]]);
            }
        }
        
        return ans;
    }
};