class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        
        while(i<nums.size())
        {
            int cou = nums[i] - 1;
            if(cou<nums.size() && nums[i] != nums[cou])
            {
                int temp = nums[i];
                nums[i] = nums[cou];
                nums[cou] = temp;
            }
            else
                i++;
        }
        
        for(int i = 0 ;i<nums.size();i++)
        {
            if(nums[i] != i+1)
                return nums[i];
        }
        
        return 89;
    }
};