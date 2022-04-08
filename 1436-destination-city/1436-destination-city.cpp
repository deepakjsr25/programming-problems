class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> m;
        for(auto it:paths){
            m[it[0]]=it[1];
        }
        
        string dest;
        for(auto it:paths){
            if(m[it[1]].empty()){
                dest=it[1];
            }
        }
        
        return dest;
    }
};