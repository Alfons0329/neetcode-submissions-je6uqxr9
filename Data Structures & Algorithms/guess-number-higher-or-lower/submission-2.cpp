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
        // n is inluded for the search
        long long l = 1, r = n + 1; // L inclusive , R exclusive

        while(l < r) {
            long long m = l + (r - l) / 2; // avoid overflow with long long when guess is INT_MAX
            if (guess(m) == 0) {
                return m;
            } else if (guess(m) < 0) {// guess too high, shrink to L side of binary search
                r = m;
            } else { // guess too low, shrhink ro R side of binary search
                l = m + 1;
            }
        }

        return -1;
    }
};