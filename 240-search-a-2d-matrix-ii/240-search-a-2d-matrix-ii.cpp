class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        
        int i=0;
        while(i<m){
            if(binary_search(mat[i].begin(),mat[i].end(),target)){
                return 1;
            }
            
            i++;
        }
        
        return 0;
    }
   
};