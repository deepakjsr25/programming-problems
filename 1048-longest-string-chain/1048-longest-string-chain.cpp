class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> m;
        int n=words.size();
        // vector<string> dp(n,-1);
        for(auto it:words){
            m[it]=1;
        }
        
        int maxi=1;
        for(auto it:words){
             maxi=max(maxi,countmax(it,m));
        }
        
        return maxi;
    }
    
    int countmax(string word,unordered_map<string,int>& m){
        if(word=="" || m[word]==0){
            return 0;
        }
        
        if(m[word]!=1 && m[word]!=0){
            return m[word];
        }
        
        int len=word.size(),maxi=1;
        string s="";
        for(int i=0;i<len;i++){
            maxi=max(maxi,1+countmax(s+word.substr(i+1,len),m));
            s+=word[i];
        }
        
        return m[word]=maxi;
    }
};