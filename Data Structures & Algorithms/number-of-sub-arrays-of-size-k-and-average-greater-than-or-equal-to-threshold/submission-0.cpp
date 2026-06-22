/*
Intution: Check a given "continuous" subarray and check for criteria

Appraoch: Sliding Window:
    1. l r
    2. r++, addSub(arr[r]) -> arr[l, r]
    3. if len(sub[l, r]) > k
        -> remove left side
        l++ 
    4. if len(sub[l, r]) == k 
        -> calculate avg
        result++ if avg >= th

Dry run:
    arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
           lr
           l r
           l   r (avg = 2, res = 0)
             l   r (avg = 2, res= 0)
                 l.  r (2, 5, 5, , avg = 4, res = 1)
                   l.  r (5, 5, 5, avg = 5 res = 2)
                     l.  r (5, 5, 8 avg = 6, res = 3)
    
    avg will not integers, we might need to use ceiling or copmare with k * th (beetter)

    arr = [5, 5, 5], k = 3, threshold = 4
           l.    r (avg = 5, res = 1)

    arr = [5, 5, 5], k = 3, threshold = -100
           l.    r (avg = 5, res = 0)
Compelxity:
    Time: O(N) N = arr.size() linear processing
    Space: O(1) no additional array space required

*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n = arr.size(), l = 0;
        int windowSum = 0, res = 0;
        for(int r = 0; r < n; r++) {
            windowSum += arr[r];

            // contract if window too big
            if (r - l + 1 > k) {
                windowSum -= arr[l];
                l++;
            }

            // window size just right
            if (r - l + 1 == k) {
                res += (windowSum >= k * th);
            }
        }

        return res;
    }
};


/*
Dry run after coding;
    arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
           l   r  (wS = 6, k * th = 12, res = 0)
             l   r  (wS = 6, k * th = 12, res = 0)
               l   r  (wS = 9, k * th = 12, res = 0)
                  l   r  (wS = 9 + 5 - 2, k * th = 12, res = 1)
                    l   r  (wS = 12 + 5 - 2, k * th = 12, res = 2)
                      l   r  (wS = 15 + 8 - 5, k * th = 12, res = 3)


*/