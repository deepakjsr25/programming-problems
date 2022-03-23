class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // return startValue >= target ? startValue - target : 1 + target % 2 + brokenCalc(startValue, (target + 1) / 2);
        
        // My  solution;
        if(target<=startValue){
            return startValue-target; 
        }
        
        if((target&1)){
            return 1+brokenCalc(startValue, target+1);
        }
        
        return 1+brokenCalc(startValue, target/2);
        
    }
};