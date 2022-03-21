class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> st(26,-1);
        vector<int> end(26,-1);
        vector<int> v(n,0);
        
        for(int i=0;i<n;i++){
            if(st[s[i]-'a']==-1){
                st[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }
        
        int start=0,en=end[s[0]-'a'];
        v[0]=start;
        for(int i=1;i<n;i++){
            if(start==en){
                start=st[s[i]-'a'];
                en=end[s[i]-'a'];
            }
            if(st[s[i]-'a']>en){
                start=st[s[i]-'a'];
                en=end[s[i]-'a'];
            }
            else if(st[s[i]-'a']<en && end[s[i]-'a']>en){
                en=end[s[i]-'a'];
            }
            
            
            
            v[i]=start;
        }
        
        v.push_back(-1);
        int i=0,cnt=0;
        vector<int> ans;
        while(i<n){
            // cout<<v[i];
            while(i<n && v[i]==v[i+1]){
                cnt++;
                i++;
            }
            
            ans.push_back(cnt+1);
            cnt=0;
            i++;
        }
        
        return ans;
    }
};