class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0;
        vector<int> v(200,-1);
        int n=s.length(),maxi=0;
        
        if(n==0 ){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            int map=s[i];
            if(v[map]==-1){
                v[map]=i;
                cnt++;
            }
            else{
                if(cnt>=i-v[map]){
                    cnt=i-v[map];
                }
                else{
                    cnt++;
                }
                
                v[map]=i;
            }
            
            maxi=max(maxi,cnt);
        }
        
        return maxi;
    }
};

// "abba"
// "tmmzuxt"