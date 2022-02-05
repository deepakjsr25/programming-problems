class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        list<int> nums;
        list<int>::iterator it = nums.begin();
        bool is_even = true;
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        
        while(i<n1 && j<n2){
            is_even = !is_even;
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                if (it == nums.end() || (is_even && (*it) <= nums1[i])){
                    it++;
                }
                if (!is_even && (*it) > nums1[i]){
                    it--;
                }
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                if (it == nums.end() || (is_even && (*it) <= nums2[j])){
                    it++;
                }
                if (!is_even && (*it) > nums2[j]){
                    it--;
                }
                j++;
            }
        }
        
        while(i<n1){
            nums.push_back(nums1[i]);
            is_even = !is_even;
            if (it == nums.end() || (is_even && (*it) <= nums1[i])){
                 it++;
            }
            if (!is_even && (*it) > nums1[i]){
                it--;
            }
            i++;
        }
        
        while(j<n2){
            nums.push_back(nums2[j]);
            is_even = !is_even;
            if (it == nums.end() || (is_even && (*it) <= nums2[j])){
                 it++;
            }
            if (!is_even && (*it) > nums2[j]){
                it--;
            }
            j++;
        }
        
        return (!is_even)? *it : (*it + *prev(it)) / 2.0;
    }
};