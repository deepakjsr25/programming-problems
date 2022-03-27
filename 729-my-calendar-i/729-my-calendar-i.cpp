class MyCalendar {
public:
    unordered_map<int,pair<int,int>> m;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        return add(0,0,start,end);
    }
    
    bool add(int st, int si, int l, int r){
        if(m.find(si)==m.end()){
            m[si]=make_pair(l,r);
            return 1;
        }
        
        if((m[si].first<l && l<m[si].second) || (m[si].first<r && r<m[si].second)){
            return 0;
        }
        if(m[si].first>=r){
            return add(0,si*2+1,l,r);
        }
        if(m[si].second<=l){
            return add(0,si*2+2,l,r);
        }
        
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */