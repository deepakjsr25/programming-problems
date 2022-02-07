class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        char ans;
        
        for(auto it:s){
            // cout<<it<<endl;
            m[it]++;
        }
        
        for(auto it:t){
            if(m[it]==0){
                ans=it;
            }
            else{
                m[it]--;
            }
            // m[it]++;
        }
        
        return ans;
    }
};