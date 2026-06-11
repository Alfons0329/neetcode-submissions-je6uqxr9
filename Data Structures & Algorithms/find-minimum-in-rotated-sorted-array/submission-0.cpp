class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0]; // Initialize with a real element to prevent arbitrary overflow limits
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            res = min(res, nums[mid]);
            
            // Unambiguous check against right bound
            if (nums[mid] > nums[right]) {
                left = mid + 1;  // Drop-off point is on the right
            } else {
                right = mid - 1; // Right side is sorted, minimum is at mid or to the left
            }
        }
        return res;
    }
};
