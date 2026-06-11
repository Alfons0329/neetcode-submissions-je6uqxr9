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