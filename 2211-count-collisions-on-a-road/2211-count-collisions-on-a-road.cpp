class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int coll=0;
        int cnt=0;
        if(directions[0]=='R'){
            cnt++;
        }
        
        for(int i=1;i<n;i++){
            if(directions[i]=='R'){
                cnt++;
                continue;
            }
            
            if(directions[i-1]=='R' && directions[i]=='L'){
                coll++;
                directions[i-1]='S';
                directions[i]='S';
            }
            else if(directions[i-1]=='S' && directions[i]=='L'){
                coll+=1;
                directions[i]='S';
            }
            
            coll+=cnt;
            cnt=0;
        }
                
        return coll;
    }
};

