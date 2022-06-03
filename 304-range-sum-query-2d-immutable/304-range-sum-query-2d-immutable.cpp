class NumMatrix {
public:
    
    vector<vector<int>> nums;
    NumMatrix(vector<vector<int>>& matrix) {
       int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        
        nums = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = nums[row2][col2];
        int extra = ((col1-1)>=0?nums[row2][col1-1]:0)+((row1-1>=0)?nums[row1-1][col2]:0) - ((row1-1>=0 && col1-1>=0)?nums[row1-1][col1-1]:0);
        
        return total-extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */