class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        // return startValue >= target ? startValue - target : 1 + target % 2 + brokenCalc(startValue, (target + 1) / 2);
        if(target<=startValue){
            return startValue-target; 
        }
        
        if((target&1)){
            return 1+brokenCalc(startValue, target+1);
        }
        
        // if(target>=(startValue*2)){
            return 1+brokenCalc(startValue, target/2);
        // }
        
        // int cal=startValue-target/2;
        // int cal2=target+1-startValue;
        // if(cal<=cal2){
        //     return 1+brokenCalc(startValue, target/2);
        // }
        
//         long long op1=1+brokenCalc(startValue, target/2);
//         long long op2=1+brokenCalc(startValue, target+1);
        
//         return min(op1,op2);
        
        // return 0;
    }
};