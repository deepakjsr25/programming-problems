class KthLargest {
public:
    multiset<int> m;
    int kth,n=0;
    KthLargest(int k, vector<int>& nums) {
        m.insert(nums.begin(),nums.end());
        n=nums.size();
        kth=k;
    }
    
    int add(int val) {
        m.insert(val);
        n++;
        auto kth_itr=next(m.begin(), n-kth);
        return *kth_itr;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */