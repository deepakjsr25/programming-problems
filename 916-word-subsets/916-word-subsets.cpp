class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        vector<int> universal(26,0);
        int n2=words2.size(),n=words1.size();
        for(int i=0;i<n2;i++){
            vector<int> v(26,0);
            int len2=words2[i].size();
            for(int j=0;j<len2;j++){
                v[words2[i][j]-'a']++;
            }
            
            for(int k=0;k<26;k++){
                universal[k]=max(universal[k],v[k]);
            }
        }
        
        for(int i=0;i<n;i++){
            vector<int> v(26,0);
            int len=words1[i].size();
            for(int j=0;j<len;j++){
                v[words1[i][j]-'a']++;
            }
            
            bool flag=1;
            for(int k=0;k<26;k++){
                if(universal[k]>v[k]){
                    flag=0;
                    break;
                }
            }
            
            // cout<<flag<<endl;
            
            if(flag){
                // cout<<i
                ans.push_back(words1[i]);
            }
            // cout<<"vv"<<endl;
        }
        
        return ans;
    }
};