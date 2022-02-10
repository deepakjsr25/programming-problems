// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n=nums.size();
//         unordered_map<int,int> m;
//         int cnt=0,sum=0;
//         m[sum]=1;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             m[sum]=1;
//             if(nums[i]==k){
//                 cnt++;
//             }
//             else{
//                 if(m[sum-k]){
//                     cnt++;
//                 }
//             }
//         }
        
//         return cnt;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currentsum = 0;
        int cnt =0;
        unordered_map<int,int> m;
        for(int i =0;i<n;i++)
        {
            currentsum+=nums[i];
            if(currentsum==k)
                cnt+=1;            
            if(m[currentsum-k]!=0)
                cnt+=m[currentsum-k];
            ++m[currentsum];            
        }
        
        return cnt;
    }
};