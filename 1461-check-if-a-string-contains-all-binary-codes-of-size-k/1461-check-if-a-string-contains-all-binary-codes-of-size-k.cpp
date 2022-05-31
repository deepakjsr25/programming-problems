class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len=s.length();
        int cnt=0;
        int req=1<<k;
        int allones=req-1;
        vector<bool> num(req);
        int b=0;
        
        for(int i=0;i<len;i++){
            b=((b<<1)&allones) | (s[i]-'0');
            
            if(i>=k-1 && !num[b]){
                num[b]=1;
                req--;
                if(req==0){
                    return 1;
                }
            }
        }
        
        
        return 0;
    }
};