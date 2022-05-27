class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num){
            cnt++;
            if(num&1){
                num--;
            }
            else{
                num=num>>1;
            }
        }
        
        return cnt;
    }
};