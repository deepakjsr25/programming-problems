class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        for(int i=n-1;i>=0 && k>0;i--){
            // k+=num[i];
            // num[i]=k%10;
            // k/=10;
            num[i]+=k;//34
            k=num[i]/10;
            num[i]=num[i]%10;
        }
        
        while(k>0){
            num.insert(num.begin(),k%10);
            k/=10;
        }
        
        return num;
    }
};