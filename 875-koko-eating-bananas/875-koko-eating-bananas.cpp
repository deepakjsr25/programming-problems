class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=*max_element(piles.begin(),piles.end());
        
        while(left<right){
            int mid=(left+right)/2;
            int currspeed=0;
            for(int it:piles){
                currspeed+=(it/mid) + (it%mid!= 0);
            }
            if(currspeed<=h){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        
        return right;
    }
};