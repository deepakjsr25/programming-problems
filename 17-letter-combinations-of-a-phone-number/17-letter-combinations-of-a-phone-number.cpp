class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        
        vector<string> v(11);
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        
        function<void(int,string)> backtrack = [&](int i,string currstr){
            if(currstr.length()==n){
                ans.push_back(currstr);
                return;
            }
            
            for(auto c : v[digits[i]-'0']){
                backtrack(i+1,currstr+c);
            }
            
            return;
        };
        
        backtrack(0,"");
        
        return ans;
        
    }
};