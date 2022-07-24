class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int cost=0;
        int maxval=neededTime[0];
        
        int i=1;
       
        while(i<n){
            if(colors[i]==colors[i-1]){
                if(maxval>neededTime[i]){
                    cost+=neededTime[i];
                }
                else{
                    cost+=maxval;
                    maxval=neededTime[i];
                }
            }
            else{
                maxval=neededTime[i];
            }
            
            i++;
        }
        
        return cost;
    }
};