class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long n = horizontalCuts.size();
        long long m = verticalCuts.size();
        long long maxi = max(horizontalCuts[0],h-horizontalCuts[n-1]);
        long long maxi2 = max(verticalCuts[0],w-verticalCuts[m-1]);
        
        for(int i = 1;i<n;i++)
        {
            long long k = horizontalCuts[i]-horizontalCuts[i-1];
            maxi = max(maxi,k);
        }
        for(int i = 1;i<m;i++)
        {
            long long k = verticalCuts[i]-verticalCuts[i-1];
            maxi2 = max(maxi2,k);
        }
        
        return (maxi2*maxi)%(1000000007);
    }
};