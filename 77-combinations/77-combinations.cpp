class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        
        combfunc(n,k,1,v,ans);
        
        return ans;
    }
    
    void combfunc(int n, int k,int i,vector<int> v,vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(v);
            return;
        }
        
        while(i<=n){
            v.push_back(i);
            combfunc(n,k-1,i+1,v,ans);
            v.pop_back();
            i++;
        }
        
        return;
    }
};