class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // unordered_map<string,int> mp;
        vector<string> ans;
        int n=words.size();
        int len2=pattern.size();
        
        char ac='a';
        vector<int> v(26,0);
        for(int i=0;i<len2;i++){
            if(!v[pattern[i]-'a']){
                v[pattern[i]-'a']=i+1; 
                pattern[i]=ac;
                ac++;
            }
            else{
                pattern[i]=pattern[v[pattern[i]-'a']-1];
            }
        }
        
        // cout<<pattern;
        
        // mp[pattern]=1;
        for(int i=0;i<n;i++){
            int len=words[i].size();
            if(len2!=len){
                break;
            }
            
            ac='a';
            vector<int> v2(26,0);
            string temp=words[i];
            for(int j=0;j<len2;j++){
                if(!v2[words[i][j]-'a']){
                    v2[words[i][j]-'a']=j+1; 
                    words[i][j]=ac;
                    ac++;
                }
                else{
                    words[i][j]=words[i][v2[words[i][j]-'a']-1];
                }
            }
            // cout<<words[i]<<endl;
            if(pattern==words[i]){
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};