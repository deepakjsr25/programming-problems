class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> m;
        string dest=paths[0][0];
        for(auto it:paths){
            m[it[0]]=it[1];
            
            while(!m[dest].empty()){
                dest=m[dest];
            }
        }
                
        return dest;
    }
};