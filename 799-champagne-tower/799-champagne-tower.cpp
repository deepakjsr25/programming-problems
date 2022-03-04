class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(100,vector<double> (100,0.0));
        v[0][0]=poured;
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){
                if(v[i][j]<1){
                    continue;
                }
                v[i+1][j]+=(v[i][j]-1)/2;
                v[i+1][j+1]+=(v[i][j]-1)/2;
            }
        }
        
//         for(int i=0;i<=query_row;i++){
//             for(int j=0;j<=i;j++){
//                 cout<<v[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        return min(1.0,v[query_row][query_glass]);
    }
};