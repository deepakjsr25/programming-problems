class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mi=0,ma=0,profit=0;
        
        for(int i=0;i<prices.size();i++)
        {
            ma=i;//2
            if(prices[i]>prices[mi])
                profit+=prices[ma]-prices[mi];
            
            mi=i;//1
        }
        return profit;
    }
};