class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() { 
    }
    
    int next(int price) {
        if(s.empty()){
            s.push(make_pair(price,1));
            return 1;
        }
        
        int i=1;
        while(!s.empty() && s.top().first<=price){
            i+=s.top().second;
            s.pop();
        }
        s.push(make_pair(price,i));
        return i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */