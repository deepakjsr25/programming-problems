class Solution {
public:
    int addDigits(int num) {
        if(num==0){
            return 0;
        }
        int sum = log10(num)+1;
        
        while(sum != 1){
            sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            num=sum;
            sum=log10(num)+1;
        }
        return num;
    }
};