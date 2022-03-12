class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        
        string s=countAndSay(n-1);
        int j=1;
        int len=s.size();
        string ans="";
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]){
                j++;
            }
            else{
                ans+=to_string(j)+s[i-1];
                j=1;
            }
        }
        
        ans+=to_string(j)+s[len-1];
        return ans;
    }
};