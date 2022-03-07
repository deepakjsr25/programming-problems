class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return nums;
        }
        
        vector<int> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push_back(nums[i]);
            }
            else{
                    while(!st.empty() && __gcd(st.back(),nums[i])>1){
                        int t=st.back();
                        int g=__gcd(t,nums[i]);
                        nums[i]=(t/g)*nums[i];
                        st.pop_back();
                    }
                    st.push_back(nums[i]);
                }
        }
        
        
        return st;
    }
};