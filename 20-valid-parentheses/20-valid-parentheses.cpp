class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
        
        for(int i =0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
                st.push(s[i]);
            
            if(s[i] == ')' || s[i] == '}' || s[i] == ']' )
            {
                if(st.empty())
                return false;
                // cout<<st.top()<<endl;
                
                if(st.top() == '(' && s[i] == ')')
                    st.pop();
                else if(st.top() == '{' && s[i] == '}')
                    st.pop();
                else if(st.top() == '[' && s[i] == ']')
                    st.pop();
                else
                    return false;
            }
        }
        
        if(st.empty())
        return true;
        
        return false;
    }
};