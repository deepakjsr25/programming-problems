class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int cnt =0;
        int left,right;
        for(int i=0;i<len;i++)
        {
            cnt++;
            left = i-1;
            right = i+1;
            while(left>=0 && right<len)
            {
                if(s[left] == s[right])
                    cnt++;
                else
                    break;
                left--;
                right++;
            }
        }
        
        for(int i=0;i<len-1;i++)
        {
            if(s[i]!=s[i+1])
                continue;
            
            cnt++;
            left = i-1;
            right = i+2;
            
            while(left>=0 && right<len)
            {
                if(s[left] == s[right])
                    cnt++;
                else
                    break;
                left--;
                right++;
            }
        }
        
        return cnt;
    }
};