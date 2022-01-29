class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            
            if(st.empty())
                left[i]=0;
            else
                left[i]=st.top()+1;
            
            st.push(i);
        }
        
        stack<int> st2;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && nums[st2.top()]>=nums[i])
                st2.pop();
            
            if(st2.empty())
                right[i]=n-1;
            else
                right[i]=st2.top()-1;
            
            st2.push(i);
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            int x = nums[i]*(right[i]-left[i]+1);
            maxi=max(maxi,x);
        }
        
        return maxi;
    }
};