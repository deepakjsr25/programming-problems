class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x,y,cx=0,cy=0;
        vector<int> v;
        
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                cx++;                    
            }
            else if(nums[i]==y){
                cy++;
            }
            else if(!cx){
                cx=1;
                x=nums[i];
            }
            else if(!cy){
                cy=1;
                y=nums[i];
            }
            else{
                cx--;
                cy--;
            }
            
        }
        
        int req=n/3;
        int cnt1=0,cnt2=0;
        
        for(auto it:nums){
            if(it==x){
                cnt1++;
            }
            
            if(it==y){
                cnt2++;
            }
        }
        
        if(cnt1>req){
            v.push_back(x);
        }
        
        if(cnt2>req){
            v.push_back(y);
        }
        
        return v;
    }
};

// [1,1,1,1,1,2,2,2,3,3,3,4,4,3]

// https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html