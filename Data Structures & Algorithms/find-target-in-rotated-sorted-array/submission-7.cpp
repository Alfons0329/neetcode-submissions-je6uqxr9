class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(); // Half-open interval: [l, r)

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;

            // Safe right-bound assessment using r - 1
            if (nums[m] <= nums[r - 1]) {
                if (target > nums[m] && target <= nums[r - 1]) {
                    l = m + 1; 
                } else {
                    r = m; // Exclusive right update
                }
            } 
            else {
                if (target >= nums[l] && target < nums[m]) {
                    r = m; 
                } else {
                    l = m + 1; 
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
    [3, 1] and search 1, initally, l = 0 , m = 1, r = 2 
    [3, 1] -> actually the ride side is arleady sorted, so if we use nums[m] < nums[r - 1], then we misunderstandingly
    think R side is not sorted, but actually not. nums[1] <= num[2 - 1] so actually sortd, we just "CHEATED" ourself

*/