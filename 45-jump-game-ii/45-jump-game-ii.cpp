class Solution {
public:
    int jump(vector<int>& nums) {        
        int minReqJump = 0, lcj = 1, lnj = 1;
	    for (int i = 0; i < nums.size()-1; ++i) {
            lcj--;
		    lnj = max(lnj-1, nums[i]);
            if (lcj == 0) {
			lcj = lnj;
			minReqJump++;
		    }
	    }
	    return minReqJump;
    }
};