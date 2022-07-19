class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        for(int i=0;i<=rowIndex;i++){
            vector<int> v(i+1);
            for(int j=0;j<i+1;j++){
                if(j==0 || j==i){
                    v[j]=1;
                    continue;
                }
                v[j]=prev[j]+prev[j-1];
            }
            if(i==rowIndex){
                return v;
            }
            prev=v;
        }
        
        return prev;
    }
};