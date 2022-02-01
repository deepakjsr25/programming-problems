class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> v(n,-1);
        v[0]=0;
        int currprofit=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            if(prices[i]-prices[v[i-1]] > currprofit){
                v[i]=v[i-1];
                currprofit=prices[i]-prices[v[i-1]];
            }
            else{
                v[i]=i;
                maxi+=currprofit;
                currprofit=0;
            }
        } 
        
        return maxi+currprofit;
    }
};