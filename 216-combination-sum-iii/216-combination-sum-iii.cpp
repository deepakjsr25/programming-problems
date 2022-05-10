class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num(10,0);
        vector<int> v;
        vector<vector<int>> ans;
        int sum=0;
        combinationSum(ans,v,num,n,k,sum,1);
        
        return ans;
    }
    
    void combinationSum(vector<vector<int>> &ans,vector<int> v,vector<int> num,int n,int k,int sum,int j){
        if(v.size()>k){
            return;
        }
        
        if(sum==n && v.size()==k){
            ans.push_back(v);
            return;
        }
        
        for(int i=j;i<=9;i++){
            if(!num[i]){
                sum+=i;
                v.push_back(i);
                num[i]=1;
                combinationSum(ans,v,num,n,k,sum,i+1);
                v.pop_back();
                num[i]=0;
                sum-=i;
            }
        }
        
        return;
    }
};