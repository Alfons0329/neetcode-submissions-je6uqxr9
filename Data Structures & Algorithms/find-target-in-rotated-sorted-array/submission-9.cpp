class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(); // Half-open interval: [l, r)

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;

            // Safe right-bound assessment using r - 1
            if (nums[m] >= nums[l]) {
                if (target >= nums[l] && target <= nums[m]) {
                    r = m;  // in this half
                } else {
                    l = m + 1; // in the other half
                }
            } 
            else {
                if (target > nums[m] && target <= nums[r - 1]) {
                    l = m + 1; // in this half 
                } else {
                    r = m;  // in other half
                }
            }
        }
        return -1;
    }
};


/*
i Think I got it!

Use he half-open interval [ )

if right is sorted -> need to include the middle point to avoid missing
    search the right side, how do we search ?
        keep search in this side -> nums[r - 1] >= target > nums[m], l = m + 1
        (note no equal because if target == nums[m], then we "shoudl have" already return the answer) 
        switch to the other side -> r = m
        (note not r = m - 1 because we use the half open interval)
else
    serach the left side, how do we search ?
        keep seatch in this side -> nums[l] <= target < nums[m], r = m
        (note no equal because if target == nums[m], then we "shoudl have" already return the answer) 
        switch to other side -> l = m + 1
        (note not l = m because we use the half open inteval)


This prevents the egde case
    [3, 1] and search 3, initally, l = 0 , m = 1, r = 2 
    [3, 1] -> actually the ride side is arleady sorted, so if we use nums[m] < nums[r - 1], then we misunderstandingly
    think R side is not sorted, but actually not. nums[1] <= num[2 - 1] so actually sortd, we just "CHEATED" ourself

    When we use <
        right side unsorted 
        go else, target = 3, nums[l] = 3 nums[m] = 1 nums[r - 1] = 1 -> target NOT in this interval , should search the r side
        l = m + 1
        l = 2, r = 2 terminated, return -1



    When we use <=
        right side sorted 
        dont go else, target = 3, nums[l] = 3 nums[m] = 1 nums[r - 1] = 1 -> target is NOT in this inteval , should search the l side
        r = m 
        l = 0, r = 0 , m = 0, FOUND!

*/