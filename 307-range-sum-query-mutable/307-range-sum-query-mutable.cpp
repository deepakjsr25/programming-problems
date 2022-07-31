class NumArray {
    int n;
    vector<int> st;
public:
    NumArray(vector<int>& a) {
        n=a.size();
        st.resize(4*n+20,0);
        for(int i=0;i<n;i++){
            up(0,0,n-1,i,a[i]);
            // cout<<st[0]<<" ";
        }
        // for(auto it:st){
        //     cout<<it<<" ";
        // }
    }
    
    void update(int i, int v) {
        up(0,0,n-1,i,v);    
    }
    
    int sumRange(int l, int r) {
        return query(0,0,n-1,l,r);
    }
    
    /// contructing segmented tree
    void up(int tind,int tl,int tr,int ind,int v){
        if(tl==tr){
            st[tind]=v;
            return;
        }
        int m=(tl+tr)/2,l=1+(tind<<1);
        if(ind<=m)
            up(l,tl,m,ind,v);
        else
            up(l+1,m+1,tr,ind,v);
        st[tind]=st[l]+st[l+1];
        // cout<<st[0]<<" ";
    }
    
    int query(int tind,int tl,int tr,int ql,int qr){
        if(tl>tr||ql>tr||tl>qr)
            return 0;
        if(ql<=tl&&qr>=tr)
            return st[tind];
        int m=(tl+tr)/2,l=1+(tind<<1);
        return query(l,tl,m,ql,qr)+query(l+1,m+1,tr,ql,qr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// ["NumArray","sumRange","update","sumRange","update","sumRange"]
// [[[1,2,5,6,4,9]],[0,2],[1,2],[0,2],[5,13],[1,5]]