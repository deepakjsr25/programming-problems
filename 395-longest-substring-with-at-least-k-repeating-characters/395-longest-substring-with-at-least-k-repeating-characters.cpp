class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        
        if(n==0 || n<k){
            return 0;
        }
        
        if(k==1){
            return n;
        }
        
        unordered_map<int,int> m;
        for(auto c:s){
            m[c]++;
        }
        
        int l=0;
        while(l<n && m[s[l]]>=k){
            l++;
        }
        
        if(l>=n-1){
            return l;
        }
        
        int len1=longestSubstring(s.substr(0,l), k);
        
        while(l<n && m[s[l]]<k){
            l++;
        }
        
        int len2=longestSubstring(s.substr(l,n-l), k);
        
        return max(len1,len2);
    }
};