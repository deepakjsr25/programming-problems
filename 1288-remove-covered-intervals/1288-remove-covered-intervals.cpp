class Solution {
public:   
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int cnt=1,low=v[0][0],high=v[0][1];
        
        for(int i=1;i<n;i++){
            if(low<v[i][0] && high<v[i][1]){
                cnt++;
            }
            if(low<=v[i][0] && high<v[i][1]){
                low=v[i][0];
                high=v[i][1];
            }
        }        
        return cnt;
    }
};