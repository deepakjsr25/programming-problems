class Solution {
public:
    string removeDuplicates(string s, int k) {
        unordered_map<int,pair<char,int>> mp;
        vector<pair<char,int>> st;
        int len=s.size();
        
        for(int i=0;i<len;i++){
            // cout<<s[i]<<endl;
            // for(auto it:st){
            //     cout<<it.first;
            // }
            // cout<<endl;
            if(st.empty()){
                st.push_back(make_pair(s[i],i));
                mp[i]=make_pair(s[i],1);
            }
            else{
                auto mat=st.back();
                // int ch=s[i];
                if(mat.first==s[i]){
                    if(mp[mat.second].second==k-1){
                        int cnt=k-1;
                        while(!st.empty() && st.back().first==s[i] && cnt){
                            cnt--;
                            st.pop_back();
                        }
                    }
                    else{
                        mp[i]=make_pair(s[i],mp[mat.second].second+1);
                        st.push_back(make_pair(s[i],i));
                    }
                }
                else{
                    st.push_back(make_pair(s[i],i));
                    mp[i]=make_pair(s[i],1);
                }
            }
        }
        
        string ans;
        for(auto it:st){
            ans.push_back(it.first);
        }
        
        return ans;
    }
};