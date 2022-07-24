class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        int v[26]={0};
        int maxi=0;
        
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            maxi=max(maxi,v[s[i]-'a']);
        }
    
        vector<int> v2(maxi+1,0);
        for(int i=0;i<26;i++){
            if(v[i]>0){
                v2[v[i]]++;
                // cout<<v[i]<<endl;
            }
        }
        
        // cout<<maxi<<endl;
        // for(int i=0;i<=maxi;i++){
        //     cout<<i<<" "<<v2[i]<<endl;
        // }
        
        int i=maxi,j=maxi,ans=0;
        while(j>=0 && i>=1){
            while(v2[i]>1 && j>=0){
                if(j==0 || v2[j]==0){
                    ans+=(i-j);
                    // cout<<i<<" "<<j<<" "<<i-j<<endl;
                    v2[j]=1;
                    v2[i]--;
                }
                if(j!=0){
                    j--;
                }
            }
            if(i==j){
                j--;
            }
            
            i--;
        }
        
        return ans;
    }
};


// "adiiijjjjaabbbbjdkkedddeffhhhhiiekkeeffifgghhjfggggjjhikkkk

// "accdcdadddbaadbc"