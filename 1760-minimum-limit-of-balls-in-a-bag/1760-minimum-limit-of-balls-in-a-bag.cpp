class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int len=nums.size();
                
        while(low<=high){//1 9  1<4 3<4
            int mid=(low+high)/2;//5 2  3
            int cnt=0;
            for(int i=0;i<len;i++){
                cnt+=((nums[i]+mid-1)/mid)-1;
            }
            
            if(cnt>maxOperations){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        
        return low;
    }
};