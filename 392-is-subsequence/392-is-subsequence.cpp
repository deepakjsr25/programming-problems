class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1>n2){
            return 0;
        }
        
        if(s==t){
            return 1;
        }
        
        int i=0,j=0;
        while(j<n2 && i<n1){
            if(s[i]==t[j]){
               i++;
            }
            j++;
        }
        
        if(i!=n1){
            return 0;
        }
        
        return 1;
    }
};