class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int n2 = version2.size();
        
        
        int i=0,j=0;
        int s=0,s2=0;
        
        while(i<n){
            if(version1[i]=='.'){
                break;
            }
            s=s*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2){
            if(version2[j]=='.'){
                break;
            }
            s2=s2*10+(version2[j]-'0');
            j++;
        }
        
        
        if(s>s2){
            return 1;
        }
        
        if(s==s2){
            if(i==n && j==n2){
                return 0;
            }
            
            if(i==n){
                return compareVersion("",version2.substr(j+1));
            }
            
            if(j==n2){
                return compareVersion(version1.substr(i+1),"");
            }
            
            return compareVersion(version1.substr(i+1),version2.substr(j+1));
        }
        
        return -1;
    }
};