class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int n=s.length();

        part(s,v,ans,0);
        
        return ans;
    }
    
    void part(string s,vector<string> v,vector<vector<string>>& ans,int i){
        int n=s.length();
        if(i==n){
            ans.push_back(v);
            return;
        }
                   
        for(int j=i;j<n;j++){ 
            int len=j-i+1;
            string st=s.substr(i,len);
            int start=0;
            int end=len-1;
                
            while(start<=end){
                if(st[end]==st[start]){
                    start++;
                    end--;
                }
                else{
                    break;
                }
            }
                               
            if(start>end){
                v.push_back(st);
                part(s,v,ans,j+1);
                v.pop_back();
            }
        }
        
        return;
    }
};