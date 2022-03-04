class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n,-1);
        
        if(k==0){
            return nums;
        }
        
        int len=2*k+1;
        
        if(len>n){
            return v;
        }
        
        int to=n-len,i=0,j=0;
        long long sum=0;
        while(i<n){
            if(i-j+1<=len){
                sum+=nums[i];
                i++;
            }
            else{
                v[j+k]=sum/len;
                sum-=nums[j];
                j++;
            }
        }
        v[j+k]=sum/len;
        return v;
    }
};