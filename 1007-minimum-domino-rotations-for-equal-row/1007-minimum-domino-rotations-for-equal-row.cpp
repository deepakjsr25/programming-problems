class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int len=tops.size();
        
        int cnt=0,cnt2=0;
        int num,num2;
        for(int i=0;i<len;i++){
            if(cnt==0){
                num=tops[i];
            }
            
            if(cnt2==0){
                num2=bottoms[i];
            }
            
            cnt+=(num==tops[i])?1:-1;
            cnt2+=(num2==bottoms[i])?1:-1;
        }
        cnt=0,cnt2=0;
        for(int i=0;i<len;i++){
           if(tops[i]==num){
               cnt++;
           } 
            
           if(bottoms[i]==num2){
               cnt2++;
           } 
        }
        
        int required;
        if(cnt>cnt2){
            for(int i=0;i<len;i++){
                if(tops[i]!=num && bottoms[i]!=num){
                    return -1;
                }
            }
            return len-cnt;
        }
        
        for(int i=0;i<len;i++){
            if(tops[i]!=num2 && bottoms[i]!=num2){
                return -1;
            }
        }
        
        return len-cnt2;
    }
};