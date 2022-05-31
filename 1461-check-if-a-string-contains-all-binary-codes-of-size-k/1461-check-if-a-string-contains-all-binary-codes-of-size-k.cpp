class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len=s.length();
        int cnt=0;
        unordered_map<string,int> m;
        for(int i=0;i<len-k+1;i++){
            string st=s.substr(i,k);
            // cout<<st<<endl;
            if(!m[st]){
                cnt++;
            }
            
            m[st]++;
        }
        
        int req=1<<k;
        // cout<<req<<" "<<cnt<<endl;
        if(cnt==req){
            return 1;
        }
        
        return 0;
    }
};