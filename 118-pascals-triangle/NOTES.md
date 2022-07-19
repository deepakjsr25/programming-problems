class Solution {
public:
vector<vector<int>> generate(int numRows) {
vector<int> v1,v2;
vector<vector<int>> ans;
v1.push_back(1);
ans.push_back(v1);
if(numRows == 1)
return ans;
v2.push_back(1);
v2.push_back(1);
ans.push_back(v2);
if(numRows == 2)
return ans;
for(int i=3;i<=numRows;i++)
{
vector<int> v3;
v3.push_back(1);
for(int j=1;j<i-1;j++)
v3.push_back(ans[i-2][j-1]+ans[i-2][j]);
v3.push_back(1);
ans.push_back(v3);
}
return ans;
}
};