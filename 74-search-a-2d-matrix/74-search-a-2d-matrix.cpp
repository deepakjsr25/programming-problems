class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();//1
        int cols=matrix[0].size();//1
        
        int start=0;
        int end=rows*cols-1;
        int mid;
        
        while(start<=end){
            mid=(start+end)/2;
            int ele=matrix[mid/cols][mid%cols];
            if(ele>target){
                end=mid-1;
            }
            else if(ele<target){
                start=mid+1;
            }
            else{
                return 1;
            }
        }
        
        return 0;
    }
};