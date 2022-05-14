class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1,maj_ele=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maj_ele==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            
            if(cnt==0){
                cnt=1;
                maj_ele=nums[i];
            }
        }
        return maj_ele;
    }
};