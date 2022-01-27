class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int i=1;
        while(i<n){
            if((islower(word[i]) && islower(word[i-1])) || (isupper(word[i]) && isupper(word[i-1])) || (isupper(word[0]) && i==1)){
                i++;
            }
            else{
                return 0;
            }
        }
        
        return 1;
    }
};