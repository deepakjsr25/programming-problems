class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        if(n==1){
            return columnTitle[0]-'A'+1;
        }
        
        return (columnTitle[n-1]-'A'+1)+26*titleToNumber(columnTitle.substr(0,n-1));
    }
};