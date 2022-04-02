class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        
        while(i<j)
        {
           if(s[i]==s[j]){
               i++;
               j--;
           }
           else{
             return ispalindrome(i+1,j,s) ||  ispalindrome(i,j-1,s);
           }
        }

        return 1;
    }
    
    bool ispalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                return 0;
        }
        
        return 1;
    }
};