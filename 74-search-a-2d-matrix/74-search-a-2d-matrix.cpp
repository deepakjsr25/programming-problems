class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();//1
        int cols=matrix[0].size();//1
        
        for(int r=0;r<rows;r++){
            if(binarysearch(matrix[r],target,cols)){
                return 1;
            }
        }
        
        return 0;
        
    }
    
    bool binarysearch(vector<int> nums, int target,int n){
        int start=0;
        int end=n-1;
        int mid;

        
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                return 1;
            }
        }
        
        return 0;
    }
};