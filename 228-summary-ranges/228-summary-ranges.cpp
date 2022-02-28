class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        string st=to_string(nums[0]);
        string end=to_string(nums[0]);
        for(int i=1;i<n;i++){
            if(stoi(end)+1==nums[i]){
                end=to_string(nums[i]);
            }
            else{
                if(st==end){
                    ans.push_back(end);
                }
                else{
                    ans.push_back(st+"->"+end);
                }
                st=to_string(nums[i]);
                end=to_string(nums[i]);
            }
        }
        
        // cout<<st<<" "<<end;
        if(st==end){
            ans.push_back(st);
        }
        else{
            ans.push_back(st+"->"+end);
        }
        
        return ans;
    }
};