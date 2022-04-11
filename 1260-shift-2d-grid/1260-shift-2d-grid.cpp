class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols=grid[0].size();
        
        vector<vector<int>> ans(rows,vector<int> (cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int temp=grid[i][j];
                int a=(j+k)/cols;
                int b=(j+k)%cols;
                int c=(i+a)%rows;
                
                ans[c][b]=temp;
            }
        }
        
        return ans;
    }
};