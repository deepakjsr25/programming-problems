/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        
        while(true)
        {
            int num = l + (r - l) / 2;
            int res = guess(num);
            if(res == 0) return num;
            else if(res == 1) l = num+1;
            else if(res == -1) r = num-1;
        }
        return -1;
    }
};