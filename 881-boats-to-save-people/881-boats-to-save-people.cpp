class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int n=people.size();
        int i=0,cnt=0,j=n-1;
                
        while(i<j){
            if(people[j]>limit){
                people[j]=-1;
                j--;
                continue;
            }
            
            if((people[i]+people[j])<=limit){
                people[i]=-1;
                people[j]=-1;
                cnt++;
                i++;
            }
            
            j--;
        }
        
        i=0;
        while(i<n){
            if(people[i]!=-1){
                cnt++;
            }
            
            i++;
        }
        
       return cnt; 
    }
};