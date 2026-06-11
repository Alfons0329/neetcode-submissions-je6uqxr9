class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;

            // Condition 1: Right half is cleanly sorted (increasing)
            if (nums[r] > nums[m]) {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1; // Target is in the right range
                } else {
                    r = m - 1; // Target is in the left range
                }
            } 
            // Condition 2: Left half is cleanly sorted (increasing) 
            // -> or say right one is not cleanly sorted
            else {
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1; // Target is in the left range
                } else {
                    l = m + 1; // Target is in the right range
                }
            }
        }
        return -1;
    }
};