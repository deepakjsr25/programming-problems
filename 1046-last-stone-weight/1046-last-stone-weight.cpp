class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        sort(v.begin(),v.end());
        cout<<v.back();
        while(v.size()>=2){
            int a=v.back();
            v.pop_back();
            int b=v.back();
            v.pop_back();
            if(a!=b){
                v.push_back(abs(a-b));
                sort(v.begin(),v.end());
            }
        }
        
        if(v.empty()){
            return 0;
        }
        
        return v.back();
    }
};