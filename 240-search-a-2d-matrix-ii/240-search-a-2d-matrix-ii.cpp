class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        
        int i=0;
        
        while(i<m){
            if(target>=mat[i][0] && target<=mat[i][n-1] && bs(mat[i],target,n)){
                return 1;
            }
            
            i++;
        }
        
        return 0;
    }
    
    bool bs(vector<int> v,int target,int n){
        int mid;
        int st=0,last=n-1;
        
        while(st<=last){
            int mid=(st+last)/2;
            if(target>v[mid]){
                st=mid+1;
            }
            else if(target<v[mid]){
                last=mid-1;
            }
            else{
                return 1;
            }
        }
        
        return 0;
    }
};