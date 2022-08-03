class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1;
        while(start<end){
            int middle=start+(end-start)/2;
            if(arr[middle]<arr[middle+1])
                start=middle+1;
            else
                end=middle;
        }
        return start;
    }
};