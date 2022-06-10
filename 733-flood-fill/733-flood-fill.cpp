class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        
        int m=image.size(),n=image[0].size();
        int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        
        int original=image[sr][sc];
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        
        while(!q.empty()){
            auto p=q.front();
            image[p.first][p.second]=newColor;
            q.pop();
            for(auto t:dir){
                int x=p.first+t[0],y=p.second+t[1];
                if(x<0 || y<0 || x>=m || y>=n || image[x][y]!=original){
                    continue;
                }
                
                q.push(make_pair(x,y));
//                 if(image[x][y]==original){
                    
//                 }
            }
        }
        
        return image;
    }
};