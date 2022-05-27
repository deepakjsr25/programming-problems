class Solution {
public:
    double soupServings(int n) {
        if(n==0){
            return 0.5;
        }
        
        if(n>4800){
            return 1.0;
        }
        
        vector<vector<double>> dp(n+1,vector<double> (n+1,-1));
        soup(dp,n,n);
        
        return dp[n][n];
    }
    
    double soup(vector<vector<double>>& dp,int a,int b){
        if(!a && !b){
            return 0.5;
        }
        
        if(!a || !b){
            return (!a)?1:0;
        }
        
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        
        double cnt=0.0;
        for(int i=25;i<=100;i+=25){
            cnt+=0.25*soup(dp,max(0,a-i),max(0,b-100+i));
        }
        
        return dp[a][b]=cnt; 
    }
};