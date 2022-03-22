class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> v(n);
        
        for(int i=0;i<n-1;i++){
            v[i]=1;
            k--;
        }
        
        if(k>26){
            v[n-1]=26;
            k-=26;
            for(int i=n-2;i>=0;i--){
                v[i]+=k;
                if(v[i]>26){
                    k=v[i]-26;
                    v[i]=26;
                }
                else{
                    break;
                }
            }
        }
        else{
           v[n-1]=k; 
        }
        
        string s="";
        for(int i=0;i<n;i++){
            char c=96+v[i];
            s+=c;
        }
         
        return s;
    }
};