class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {   
        int l=1;
        if(n==1 && flowerbed.size()==1){
            return !flowerbed[0];   
        }
        
        if(n==0){
            return 1;   
        }
        
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        
        while(l<flowerbed.size()-1 && n>0){
            if((flowerbed[l]==0 && flowerbed[l+1]==0 && flowerbed[l-1]==0)){
                flowerbed[l]=1;
                n--;
                l++;
            }
            else if(flowerbed[l]==1){
                l+=2;
            }
            else{
                l++;
            }
        }
        
        if(l==flowerbed.size()-1){
            if(flowerbed[l]==0 && flowerbed[l-1]==0){
                n--;
            }
            
        }
        
        if(n>0){
            return false;
        }
        
        return true;
    }     
};