class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                }
                // break;
            }
        }
        
        // cout<<"ffgr"<<endl;
        int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        int cnt=0;
        while(!q.empty()){
            auto p=q.front();
            // cout<<p.first<<" "<<p.second<<endl;
            grid[p.first][p.second]=-1;
            q.pop();
            int curr_cnt=0;
            for(auto t:dir){
                int x=p.first+t[0],y=p.second+t[1];
                if(x<0 || y<0 || x>=row || y>=col || grid[x][y]==0){
                    continue;
                }
                
                // if(grid[x][y]!=-1){
                //     q.push(make_pair(x,y));
                // }
                
                curr_cnt++;
            }
            // cout<<curr_cnt<<endl;
            cnt+=(4-curr_cnt);
        }
        
        return cnt;
    }
};

// [[1,1,1,1],[1,0,0,1],[1,0,0,1],[1,1,1,1]]