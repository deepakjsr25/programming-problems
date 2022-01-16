class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int n=s.length();

        part(s,v,ans,0);
        
        return ans;
    }
    
    void part(string s,vector<string> v,vector<vector<string>>& ans,int i){//aa,,,0
        int n=s.length();//2
        // cout<<i<<" "<<s<<endl;
        if(i==n){//
            // v.push_back(s);
            ans.push_back(v);
            return;
        }
                   
        for(int j=i;j<n;j++){ // 0,2
            int len=j-i+1;//1-1+1
            string st=s.substr(i,len);//a
            // cout<<i<<" "<<st<<endl;
            int start=0;
            int end=len-1;//0
                
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
                // cout<<st<<endl;
                v.push_back(st);
                part(s,v,ans,j+1);//1,0,a,ans,1
                v.pop_back();
            }
        }
        
        return;
    }
};