class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        
        for(int i=0;i<m;i++){
            if(binary_search(mat[i].begin(),mat[i].end(),target)){
                return 1;
            }
        }
        
        return 0;
    }
   
};