/*
Intuition: Use the sliding window approach when 
solving problems that require calculating or 
searching through a subset of contiguous elements 
(subarrays or substrings) within a larger sequence.


Approach:
    1. Construct 
        1-1 we create a frequency mapping to track the frequency of character in string t 
        1-2 and how many unique characters is defined as the size of map
    2. Then create L, R sliding window in s
        2-1. //Exapnd
        So when we expanding to get new character, 
        we put into our current frequency map, symbolizes the frequency map in our current sliding window
        A match is defined as when the character not only meet but it frequency. Also meet within the target.
        So in this situation, we increase the match count
        And a full viable match means the match count is equal to the count of the unique characters in the target stream t

        2-2. // Shrink
        When we have a valid answer, which means we can shrink confidently by making the left side move to right 
        to see if it's possible to get a smaller size of substring window

        And in this case means we will shrink until the fully match is no longer exist
        So during shrikning
        L++ // increase the left boundary
        
        And then decrease the character frequency of such a character in our current sliding window frequency map
        sFreq[s[L]]--;

        And if after decreasing the frequency of the sliding window is less than the target, then the match counter, decreased by one
        if (sFreq[s[L]] < tFreq[s[L]]) {
            match--;
        }

        Then we will quit the wild loop if the match is no longer up to the distinct character in string t

        So simply speaking, our match does not only find the match of the gear character, but also we need to match the frequency. 
        That's our core logic.

Dry run:

So below is the dry sample
tFreq{X1, Y1, Z1}
uniqueCharInT = tFreq.size()
matched += (sFreq[s[R]] == tFreq[s[R]])
if (matched = uniqueCharInT) {
    res = max(res, R - L + 1)
}

O. U. Z. O. D. Y. X. is the first to get XYZ without shrink
LR {O1}, matched = 0
L. R {O1, U1}, matched = 0
L. R {O1, U1, Z1}, matched = 1
L.       R {O2, U1, Z1}, matched = 1
L           R {O2, U1, Z1, D1}, matched = 1
L              R {O2, U1, Z1, D1, Y1}, mathced = 2
L                 R {O2, U1, Z1, D1, Y1, X1}, mathced = 3, res = min(INT_MAX, 7) = 7, str = OUZODYX

O. U. Z. O. D. Y. X.
   L              R {O1, U1, Z1, D1, Y1, X1} matched = 3, res = min(7, 6) = 6, str = UZODYX
      L           R {O1, U1, Z1, D1, Y1, X1} matched = 3, res = min(6, 5) = 5, str = ZODYX
         L        R {O1, U1, Z0 (NO MATCH)....} matched = 2, cannot update result

//after a few iterations
O. U. Z. O  D. Y  X  A Z V 
         L             R {O1, D1, Y1, X1, A1, Z1} matched = 3, res = min(5, 6) = 5 no update str we don't need to update the results string because the length is not shorter
               L       R {Y1, X1, A1, Z1}, the match count is still the same, but we can update the res to four and the result string is now YXAZ

The complexity analysis
    Time: O(N), because the sliding window LNR enter for each sliding window 
    we will not check up to the full length of the street as so, it will be not N^2
    Space: O(1), the fixed size to keep checking the character frequency mapping 26


*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), L = 0;
        // construct tFreq
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        // constrecut sFreq to keep track the current sliding window char -> freq mapping
        unordered_map<char, int> sFreq;
        int uniT = tFreq.size();
        int minLen = INT_MAX, matchedCnt = 0;
        // string res = s; 
        // Wrong answer, do not initialize the res to s first because we are not guaranteed to have a valid answer (e.g. s = "a", t = "b", result shoudl be empty)
        string res;

        // iterate
        for (int R = 0; R < n; R++) {
            // put into sFreq
            char rc = s[R]; // right character
            sFreq[rc]++;

            matchedCnt += (sFreq[rc] == tFreq[rc]);

            while(matchedCnt == uniT) {
                // matched, update the substr for current viable result
                string curRes = s.substr(L, R - L + 1);
                
                // so at here, 
                // we cannot compare if the current size is less than the res size 
                // because when we initialize to s and there is no update then we will have the wrong answer
                // are we initialize the result to empty strength and then the result will be always the empty stirng
                // hence the initiation comparison of length should not be based on result otherwise we will have a lose-lose condition
                /*
                // this will result in a round answer for both res = s or res = ""
                string curRes = s.substr(L, R - L + 1);
                if (curRes.size() < res.size()) {
                    res = curRes;
                }
                */

                if (curRes.size() < minLen) {
                    minLen = curRes.size();
                    res = curRes;
                }

                char lc = s[L];
                sFreq[lc]--;
                // the character to be removed does exist in the target stream, so we decrease the match if we no longer have the frequency
                matchedCnt -= (tFreq.count(lc) && sFreq[lc] < tFreq[lc]);
                L++;
            }
        }

        return res;
    }
};
