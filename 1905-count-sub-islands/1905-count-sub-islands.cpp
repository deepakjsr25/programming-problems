class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int sub_il=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    sub_il+=count(grid1,grid2,i,j,m,n);
                }
            }
        }
        
        return sub_il;
    }
    
    bool count(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || (grid2[i][j]==0)){
            return 1;
        }
        
        if(grid2[i][j]==1 && grid1[i][j]==0){
            return 0;
        }
        
        grid2[i][j]=0;
        
        int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
        int cnt=1;
        
        for(auto it:dir){
            if(cnt){
                cnt=(cnt&count(grid1,grid2,i+it[0],j+it[1],m,n));
            }
        }
        
        grid2[i][j]=!cnt;
        grid1[i][j]=0;
        return cnt;
    }
};