class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        unordered_map<string,int> m;
        if(n<10){
            return ans;
        }
        
        // if(n==10){
        //     ans.push_back(s);
        //     return ans;
        // }
        
        int i=9,j=0;
        m[s.substr(0,i-j+1)]=1;
        // cout<<s.substr(0,i-j+1);
        i++;
        j++;
        while(i<n){
            string str = s.substr(j,i-j+1);
            // cout<<str<<endl;
            if(!m[str]){
                m[str]++;
            }
            else if(m[str]==1){
                ans.push_back(str);
                m[str]++;
            }
            i++;
            j++;
        }
        
        return ans;
    }
};
