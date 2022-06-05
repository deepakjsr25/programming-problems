class Solution {
public:
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string> v(n,s);
        
        return total(v,0,n);
    }
    
    int total(vector<string> &v,int row,int n){
        if(row>=n){
            return 1;
        }
        
        int cnt=0;
        for(int col=0;col<n;col++){
            if(check(v,row,col,n)){
                v[row][col]='Q';
                cnt+=total(v,row+1,n);
                v[row][col]='.';
            }
        }
        
        return cnt;
    }
    
    bool check(vector<string> &v,int row,int col,int n){
        for(int k=0;k<n;k++){
            if(v[k][col]=='Q'){
                return 0;
            }
            
            if(row-k>=0 && col-k>=0 && v[row-k][col-k]=='Q'){
                return 0;
            }
            
            if(row-k>=0 && col+k>=0 && v[row-k][col+k]=='Q'){
                return 0;
            }
        }
        
        return 1;
    }
};