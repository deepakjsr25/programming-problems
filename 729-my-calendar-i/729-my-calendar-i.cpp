class MyCalendar {
public:
    // int v[70000000];
    unordered_map<int,pair<int,int>> m;
    // int i;
    MyCalendar() {
        // memset(v,-1,70000);
    }
    
    bool book(int start, int end) {
        return add(0,0,start,end);
    }
    
    bool add(int st, int si, int l, int r){
        if(m.find(si)==m.end()){
            m[si]=make_pair(l,r);
            return 1;
        }
        
         // cout<<m[si].first<<" "<<l<<endl;
        if((m[si].first<l && l<m[si].second) || (m[si].first<r && r<m[si].second)){
            // cout<<m[si].first<<" "<<l<<endl;
            return 0;
        }
        // cout<<"2"<<endl;
        if(m[si].first>=r){
            return add(0,si*2+1,l,r);
        }
        // cout<<"3"<<endl;
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