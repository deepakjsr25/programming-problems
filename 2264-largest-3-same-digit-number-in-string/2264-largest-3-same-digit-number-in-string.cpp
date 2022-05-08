class Solution {
public:
    string largestGoodInteger(string num) {
        int j=0;
        string ans="",temp="";
        char prev='/';
        int len=num.size();
        
        for(int i=0;i<len;i++){
            if(j<3){
                if(prev=='/' || prev==num[i]){
                    ans+=num[i];
                }
                else{
                    ans=num[i];
                    j=0;
                }
                prev=num[i];
                j++;
            }
            
            // cout<<ans<<endl;
            if(j==3){
                while(i<len && num[i]==prev){
                    i++;
                }
                if(temp=="" || stoi(ans)>stoi(temp)){
                    temp=ans;
                }
                i--;
                ans="";
                j=0;
            }
        }
        
        return temp;
    }
};