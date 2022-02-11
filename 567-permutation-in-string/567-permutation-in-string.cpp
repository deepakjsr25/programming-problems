class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size() , n = s2.size() ;
        
        vector<int> mp(26,0) , freq(26,0) ;
        
        for(char c : s1)
            mp[c-'a']++ ;
        
        for(int i=0;i<n;i++)
        {
            if(i-m>=0)
                freq[s2[i-m]-'a']-- ;
            
            freq[s2[i]-'a']++ ;
            
            if(freq==mp)
                return true ;
        }
        
        return false ;
        
    }
};