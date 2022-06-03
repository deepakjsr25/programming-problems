class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1,high=0,sum=0;
        long long n=candies.size();
        long long mini=INT_MAX;
        
        for(auto it:candies){
            sum+=it;
        }
        
        if(sum<k){
            return 0;
        }
        
        high=sum/k;//7
        long long ans=0;
        
        long long mid=1;
        while(low<=high){
            mid=(low+high)/2;//4 (5+7)/2=6  (3+7)/2=5  (4+4)/2=4
            cout<<low<<" "<<high<<" "<<mid<<endl;
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+=candies[i]/mid;
            }
            
            if(cnt>=k){//13>=9
                // mini=min(mini,mid);
                ans=mid;
                low=mid+1;//2 3
            }
            else if(cnt<k){
                high=mid-1;//4
            }
        }
        
        
        return ans;
    }
};