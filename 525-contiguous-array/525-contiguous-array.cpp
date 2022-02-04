class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        nums.insert(nums.begin(), 0);
    
        unordered_map<int, int> mp;
        int length = 0;
        int sum = 1;
        mp[sum] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i]==0?-1:1;
            if (mp.find(sum) != mp.end())
            {
                length = max(length, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }

        return length;
    }
};