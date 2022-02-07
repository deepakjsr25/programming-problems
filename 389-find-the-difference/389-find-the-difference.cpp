class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(200,0);
        char ans;
        
        for(auto it:s){
            // cout<<it<<endl;
            m[it]++;
        }
        
        for(auto it:t){
            if(m[it]==0){
                ans=(char)it;
            }
            else{
                m[it]--;
            }
        }
        
        return ans;
    }
};