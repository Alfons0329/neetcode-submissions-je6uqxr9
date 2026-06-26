/*
Intuition: Check if a continuous substring matches criteria and expand -> 

Approach:
    1 Expand the R of sliding window
    2 If we found duplicate
        2-1 Shrink L from the set until no duplicate
        2-2 Add new R to the set
    3 If no duplicate
        3-1 Update the result
        3-2 Add new R to the set

Dry run:
    "z  x  y  z  x  y  z"
     lr {z}
     l. r{z, x}
     l.    r {z, x, y}
     l.       r -> duplicate remove s[l] = z {x, y}
        l.    r -> shrink until no duplicate {x, y, z} 
        l        r -> duplicate remove s[l] = x
           l.    r -> shrink, {y, z, x}
           l.      r -> duplicate, remove s[l] = y, {z, x}
              l.   r -> shrink, {z, x, y}
              l.      r -> duplicate remove s[l] = z
                 l.   r -> shrink, {x, y, z}

Complexity:
    Time: O(N) Sliding window, most of the window not processed up to N, so no N^2
    Space: O(1) No extra space is used
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, res = 0;
        int n = s.size();
        unordered_set<char> existChar;

        for (int R = 0; R < n; R++) {
            // if char not exist, no duplicate, insert it, and update the result
            if (!existChar.count(s[R])) {
                res = max(R - L + 1, res);
            } else {
                while(existChar.count(s[R])) {
                    existChar.erase(s[L]);
                    L++;
                }
            }

            // insert the current character post processing
            existChar.insert(s[R]);
        }

        return res;
    }
};
/*

Wrong Ans:

s="p.  w.  w.  k.  e.  w"
   lr {p}
   l   r{p, w}
   l.      r {p, w} (Cannot only shrink L once, 
                    need to shrink until no duplicate, 
                    shrink once result in ww)
       l.  r  
*/
