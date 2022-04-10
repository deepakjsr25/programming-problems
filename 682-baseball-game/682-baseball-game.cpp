class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto it:ops){
            if(isdigit(it[0]) || it[0]=='-'){
                v.push_back(stoi(it));
            }
            else if(it=="C"){
                v.pop_back();
            }
            else if(it=="D"){
                v.push_back(2*v.back());
            }
            else{
                int a=v.back();
                v.pop_back();
                int b=v.back();
                int c=a+b;
                v.push_back(a);
                v.push_back(c);
            }
            
        }
                
        int sum=0;
        for(auto it:v){
            sum+=it;
        }
        
        return sum;
    }
};