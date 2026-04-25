/*
Intution: Def L and R as wall and shrink to see if we can find better result

Approach: 
    [1,7,2,5,4,7,3,6] area = min(arr[L], arr[R]) * (R - L)
    1. hence make arr[L] and arr[R] as big as possible by shrink (see if we can find higher bar)
        -> 1-1 if arr[L] < arr[R], shrink L (L++)
        -> 1-2 else shrink R (R--)
    2. update the result 

Complexity:
    Time: O(heights.size()), since L++ R-- until L == R, not able to make any more space
    Space: O(1) no extra space required

Example:

    [1,7,2,5,4,7,3,6] area = min(arr[L], arr[R]) * (R - L)
     L             R area = min(1, 6) * (7) = 7
       L           R area = min(7, 6) * (6) = 36, 36
       L         R.  area = min(7, 3) * (5) = 15
       L       R     area = min(7, 7) * (4) = 28
       L.    R.      area = min(7, 4) * (3) = 12
       L  R          arae = min(7, 5) * (2) = 10
       L R           area = min(7, 2) * (1) = 2

*/
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size() - 1; 
        int res = 0;

        while(L < R) {
            res = max(res, min(heights[L], heights[R]) * (R - L));

            // shrink to find if there exist higher bar possible
            // 1-1
            if (heights[L] < heights[R]) {
                L++;
            } else {
                R--;
            }
        }

        return res;
    }
};

/*
Dry run:
    [1,7,2,5,4,7,3,6] shoudl be 36
     L             R area = 1 * 7 = 7, res = 7
       L           R area = 6 * 6 = 36, res = 36
       L         R   area = 3 * 5 = 15, res = 36
       L       R     area = 7 * 4 = 28, res = 36
       L     R       area = 4 * 3 = 12, res = 36
       L   R         area = 5 * 2 = 10, res = 36
       L R           area = 2 * 1 = 2, res = 36


    [1, 200, 1, 1] should be 3
    L           R area = 1 * 3 = 3, res = 3
    L        R area = 1 * 2 = 2, res = 2
    L    R     area = 1 * 1 = 1, res = 1

    200 looks tall but all other bars are 1, hence cpomletely in vain
*/
