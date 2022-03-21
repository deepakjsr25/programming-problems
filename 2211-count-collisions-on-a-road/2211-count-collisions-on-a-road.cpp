class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        // vector<int> v(n,0);
        
        // left=-1,right=1,stay=0
        // -1,-1,1,1
        int coll=0;
        // if(directions[0]=='S'){
        //     v[0]=0;
        // }
        // else if(directions[0]=='R'){
        //     v[0]=1;
        // }
        // else{
        //     v[0]=-1;
        // }
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
            // else if(directions[i-1]=='R' && directions[i]=='S'){
            //     int j=i-1;
            //     while(j>=0 && directions[j]=='R'){
            //         directions[j]=='S';
            //         j--;
            //         coll++;
            //     }
            // }
            
            coll+=cnt;
            cnt=0;
        }
                
        return coll;
    }
};

// "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR"
// "SSSSSSSSSSSSSSSSSSSRRRSSSRSSSSRR"
// C=16