class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n,0));
        ans[0][0]=1;
        int k=2;
        int curr_i=0,curr_j=1;
        int rows=n-1,cols=n-1;
        
        while(rows || cols){
            while(curr_j<=cols){
                ans[curr_i][curr_j]=k;
                k++;
                curr_j++;
            }
            
            curr_j--;
            curr_i++;
            while(curr_i<=rows){
                ans[curr_i][curr_j]=k;
                k++;
                curr_i++;
            }
            
            curr_i--;
            curr_j--;
            while(curr_j>=(n-cols-1)){
                ans[curr_i][curr_j]=k;
                k++;
                curr_j--;
            }
                  
            curr_i--;      
            curr_j++;    
            while(curr_i>=(n-rows)){
                ans[curr_i][curr_j]=k;
                k++;
                curr_i--;
            }
                  
            curr_i++; 
            curr_j++;
            rows--,cols--;      
        }
                  
            return ans;      
    }
};