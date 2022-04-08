class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; /// to create a min heap
    int size;
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop(); // dont confuge pop aage se ho raha hai
        }
        
        // auto it=pq.back();
        // cout<<it<<endl;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top(); // sabse aage wala element
    }
};