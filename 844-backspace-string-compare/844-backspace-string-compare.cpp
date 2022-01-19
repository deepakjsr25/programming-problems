class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        stack<char> st;
        stack<char> st2;
        
        for(int j=l1-1;j>=0;j--){
            if(s[j]!='#'){
                if(!st.empty()){
                    char ch=st.top();
                    if(ch=='#'){
                        st.pop();
                    }
                    else{
                        st.push(s[j]);
                    }
                }
                else{
                    st.push(s[j]);
                }
            }
            else{
                st.push(s[j]);
            }
        }
        
        for(int j=l2-1;j>=0;j--){
            if(t[j]!='#'){
                if(!st2.empty()){
                    char ch=st2.top();
                    if(ch=='#'){
                        st2.pop();
                    }
                    else{
                        st2.push(t[j]);
                    }
                }
                else{
                    st2.push(t[j]);
                }
            }
            else{
                st2.push(t[j]);
            }
        }
        
        s="";
        t="";
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            if(ch=='#'){
                continue;
            }
            s+=ch;
        }
        
        while(!st2.empty()){
            char ch=st2.top();
            st2.pop();
            if(ch=='#'){
                continue;
            }
            t+=ch;
        }
        
        if(s!=t){
            return 0;
        }
        
        return 1;
    }
};