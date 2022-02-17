class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(),nums.end(),1);
        
        if(cnt1==0 || cnt1==n || cnt1==n-1){
            return 0;
        }
        
        for(int i=0;i<cnt1-1;i++){
            nums.push_back(nums[i]);
        }
        
        int mini = n;
        int curr = 0,j=0,i=0;
        
        while(i<n+cnt1-1){
            if(i<cnt1 && nums[i]==1){
                curr++;
            }
            if(i>=cnt1){
                if(nums[j]==1){
                    curr--;
                }
                if(nums[i]==1){
                    curr++;
                }
                j++;
            }
            mini = min(mini,cnt1-curr);
            i++;
        }
        
        return mini;
    }
};