class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0,total_cnt=0;
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    total_cnt++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    // int op=countenclve(grid,i,j,m,n);
                    cnt+=countenclve(grid,i,j,m,n);
                }
            }
        }
        
        return total_cnt-cnt;
    }
    
    int countenclve(vector<vector<int>>& grid,int i,int j,int m,int n){
        if((i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) ){
            return 0;
        }
        
        
        // cout<<i<<" "<<j<<endl;
        int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
        int cnt=1;
        grid[i][j]=0;
        
        for(auto it:dir){
            // cout<<it[0]<<" "<<it[1]<<endl;
            // int op=countenclve(grid,i+it[0],j+it[1],m,n);
            cnt+=countenclve(grid,i+it[0],j+it[1],m,n);
        }
        
        // cout<<cnt<<endl;
        return cnt;
    }
};