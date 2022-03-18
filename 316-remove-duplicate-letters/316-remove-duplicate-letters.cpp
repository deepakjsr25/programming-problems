class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26,0);
        vector<int> cnt(26,0);
        int n=s.size();
        string ans;
        ans.push_back(s[0]);
        v[s[0]-'a']=1;
        
        for(int i=1;i<n;i++){
            cnt[s[i]-'a']++;
        }
        
        for(int i=1;i<n;i++){
            if(v[s[i]-'a']==0){
                while(!ans.empty() && ans.back()>s[i]){
                    char ch=ans.back();
                    if(cnt[ch-'a']!=0){
                        v[ch-'a']=0;
                        ans.pop_back();
                    }
                    else{
                        break;
                    }
                }
                ans.push_back(s[i]);
                v[s[i]-'a']=1;
                cnt[s[i]-'a']--;
            }
            else{
                cnt[s[i]-'a']--;
            }
        }
        
        // string st;
        // for(int i=0;i<len;i++){
        //     if(ans[i]!='*'){
        //         st.push_back(ans[i]);
        //     }
        // }
        
        return ans;
    }
};