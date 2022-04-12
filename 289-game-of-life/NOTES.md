class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
vector<vector<int>> ans;
ans=board;
int m =board.size(),n=board[0].size();
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
int cnt =0;
if(i-1>=0 && board[i-1][j] == 1)
cnt++;
if(j-1>=0 && board[i][j-1] == 1)
cnt++;
if(j+1<n && board[i][j+1] == 1)
cnt++;
if(i+1<m && board[i+1][j] == 1)
cnt++;
if(i-1>=0 && j-1>=0 && board[i-1][j-1] == 1)
cnt++;
if(i-1>=0 && j+1<n && board[i-1][j+1] == 1)
cnt++;
if(i+1<m && j-1>=0 && board[i+1][j-1] == 1)
cnt++;
if(i+1<m && j+1<n && board[i+1][j+1] == 1)
cnt++;
if(board[i][j] == 0)
{
if(cnt==3)
ans[i][j] = 1;
}
else
{
if(cnt<2)
ans[i][j] = 0;
else if(cnt==2 ||cnt==3)
ans[i][j] = 1;
else
ans[i][j] = 0;
}
}
}
board=ans;
}
};