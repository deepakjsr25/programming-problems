class Solution {
public:
    int longestValidParentheses(string s) {
      
        int len = s.length();
        stack<int> st;
        st.push(-1);
        int maxi=0;
        // int curr_len=0;
        
        for(int i=0;i<len;i++)
        {
            if(s[i] == '(')
                st.push(i);
            
            if(s[i]==')')
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    maxi=max(i-st.top(),maxi);
            }
        }
        
        return maxi;
    }
};