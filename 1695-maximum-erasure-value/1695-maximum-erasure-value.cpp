class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int sum=0,maxi;
        int i=0,j=1;
        sum+=nums[i];
        m[nums[i]]=1;
        maxi=sum;
        
        while(j<n){
            if(m[nums[j]]==1){
                while(i<j && nums[i]!=nums[j]){
                    m[nums[i]]=0;
                    sum-=nums[i];
                    i++;
                }
            }           
            
            if(nums[i]==nums[j]){
                sum-=nums[i];
                i++;
            }
            
            m[nums[j]]=1;
            sum+=nums[j];
            maxi=max(maxi,sum);
            j++;
        }
        
        return maxi;
    }
};