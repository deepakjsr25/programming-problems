class Solution {
public:
    long long sumSubarrayMins(vector<int>& a) {
        if (a.size() == 0)  return 0;
        int mod = pow(10, 9) + 7;
        stack<pair <long long, long long>> s1,s2;
        long long left[a.size()],right[a.size()];
        for(long long i=0;i<a.size();i++){
            long long count=1;
            while(!s1.empty()&& s1.top().first>a[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push(make_pair(a[i],count));
            left[i]=count;
        }
        for(long long i=a.size()-1;i>=0;i--){
            long long count=1;
            while(!s2.empty()&& s2.top().first>=a[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(a[i],count));
            right[i]=count;
        }
        long long ans=0;
        for(long long i=0;i<a.size();i++){
            ans+=((left[i]*right[i]*a[i])%mod);
            ans%=mod;
        }
        return ans;
    }
};