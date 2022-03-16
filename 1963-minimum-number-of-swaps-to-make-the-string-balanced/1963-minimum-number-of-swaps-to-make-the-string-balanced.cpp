class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
       
        int maxi=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                cnt+=-1;
            }
            else{
                cnt+=1;
            }
            
            maxi=max(maxi,cnt);
        }
        
        return (maxi+1)/2;
    }
};