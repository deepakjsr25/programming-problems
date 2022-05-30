class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        
        int res=0;
        long int dd=abs(dividend),dv=abs(divisor);
        while(dd>=dv){
            long int mul=dv,temp=1;
            while(mul<=dd-mul){
                mul+=mul;
                temp+=temp;
            }
            
            res+=temp;
            dd-=mul;
        }
        
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)){
            return -res;
        } 
        
        return res;
    }
};