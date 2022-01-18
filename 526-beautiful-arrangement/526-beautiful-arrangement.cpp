class Solution {
public:
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
        return arrange(n,1,vis);
    }
    
    int arrange(int n,int idx,vector<int> vis){
       if(idx>n){
           return 1;
       } 
        
       int op=0; 
       int i=1; 
       while(i<=n){
           if((i%idx==0 || idx%i==0) && (vis[i]!=1)){
               vis[i]=1;
               op+=arrange(n,idx+1,vis);//2,2  3,3
               vis[i]=0;
           }
           i++;
       } 
        
       return op;
    }
};