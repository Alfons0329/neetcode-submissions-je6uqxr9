class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;

            // Condition 1: Left half is cleanly sorted (increasing)
            if (nums[l] <= nums[m]) {
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1; // Target is in the left range
                } else {
                    l = m + 1; // Target is in the right range
                }
            } 
            // Condition 2: Right half is cleanly sorted (increasing)
            else {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1; // Target is in the right range
                } else {
                    r = m - 1; // Target is in the left range
                }
            }
        }
        return -1;
    }
};