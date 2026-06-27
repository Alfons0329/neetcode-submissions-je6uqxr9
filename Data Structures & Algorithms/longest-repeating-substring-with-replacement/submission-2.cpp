/*
Intuition: Searching through a subset of contiguous elements (subarrays or substrings) within a larger sequence.  -> Sliding window ! 
Approach:
    1. In a given window size n
    2. Char need replace maxFreqChar - others (make "others" become same as maxFerqChar)
    3. for R, L of sliding window
        Valid := (R - L + 1) - (maxFreqChar) <=k --> how many "others" need to replace
        res = max(res, R - L + 1)
    4. Increase L if invalid to shrink

Dry run:
    X.  Y.  Y.  X.  
    LR {X1}, R - L + 1 - 1 = 0 - 0 + 1 - 1 <= 2, res = 1
    L.  R {X1, Y1}, R - L + 1 - 1 = 1 - 0 + 1 - 1 <= 2, res = 2
    L.      R {X1, Y2}, R - L + 1 - 2 = 2 - 0 + 1 - 2 <=2, res = 3
    L          R {X2, Y2}, R - L + 1 - 2 = 3 - 0 + 1 - 2 <= 2 = 4


    A. A. A. B. A. B. B
    LR {A1} 1 - 1 <= 1, res = 1
    L. R {A2} 2- 2 <=1, res = 2
    L.    R {A3} 3 - 3 <= 1, res = 3
    L        R {A3, B1} 4 - 3 <= 1, res = 4
    L           R {A4, B1} 5 - 4 <= 1, res = 5
    L              R {A4, B2} 6 - 4 > 1, res = 5, shrink left until valid
             L    R {A1, B2} 3 - 2 <= 1, res = 5
             L.       R {A1, B3} 4 - 3 <= 1, res = 5
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, n = s.size(), res = 0;
        int maxFreq = 0;
        int charFreq[26] = {0};

        for (int R = 0; R < n; R++) {
            // Expand
            int offset = s[R] - 'A';
            charFreq[offset]++;
            maxFreq = max(maxFreq, charFreq[offset]);

            // Contract
            while((R - L + 1 - maxFreq > k)) { // elemetn at most we can replace
                // decrease freq and update maxFreq if needed
                offset = s[L] - 'A';
                charFreq[offset]--;
                L++;


                // re-construct
                maxFreq = 0;
                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, charFreq[i]);
                }
            }

            printf("L %d R %d maxFreq %d \n", L, R, maxFreq);


            // Process
            res = max(res, R - L + 1);
        }

        return res;
    }
};
