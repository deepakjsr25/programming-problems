class Solution {
public:
    bool detectCapitalUse(string word) {
        int f = 0;
        int up = 0;
        for(int i=0;i<word.size();i++) {
            if(isupper(word[i])) {
                if(f)return false;
                up++;
            }
            else if(islower(word[i])) {
                if(up > 1)return false;
                f = 1;
            }
        }
        return true;
    }
};