// https://www.youtube.com/watch?v=KNeYi11859M&t=1303s
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        if(n<=2){
            return 1;
        }

        int indx=0;

        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1]){
                if(indx!=0){
                    return false;
                }
                indx=i;
            }
        }
        
        if(indx==0 || indx==1 || indx==n-1){
            return true;
        }
        
        if(nums[indx-1]>nums[indx+1] && nums[indx-2]>nums[indx]){
            return false;
        }
        
        return true;
    }
};