class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int min_sum=0,max_sum=0;
        for(int i=0;i<n;i++){
            max_sum+=nums[i];
            if(min_sum<nums[i]){
                min_sum=nums[i];
            }
        }
        
        // cout<<min_sum<<" "<<max_sum<<endl;
        int mid_sum,ans=INT_MAX;
        while(min_sum<=max_sum){//10  32
            mid_sum=(min_sum+max_sum)/2; //21
            int cnt=1,sum=0,curr_max_sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                // cout<<sum<<" "<<mid_sum<<endl;
                if(sum>mid_sum){
                    cnt++;
                    sum-=nums[i];
                    curr_max_sum=max(curr_max_sum,sum);
                    sum=nums[i];
                }
            }
            
            curr_max_sum=max(curr_max_sum,sum);
            // cout<<curr_max_sum<<endl;
            if(cnt<=m){
                ans=min(ans,curr_max_sum);
                max_sum=mid_sum-1; 
            } 
            else{
                min_sum=mid_sum+1;
            }
        }
        
        return ans;
    }
};