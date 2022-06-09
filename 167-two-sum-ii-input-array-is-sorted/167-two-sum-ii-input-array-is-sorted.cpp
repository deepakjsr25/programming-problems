class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> ans;
        int i=0,j=n-1;
        
        while(i<j){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }
        
        return ans;
    }
};