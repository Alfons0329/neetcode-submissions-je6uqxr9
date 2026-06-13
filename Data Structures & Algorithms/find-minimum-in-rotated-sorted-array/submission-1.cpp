class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0]; // Initialize with a real element to prevent arbitrary overflow limits
        int left = 0, right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            res = min(res, nums[mid]);
            
            if (nums[mid] <= nums[right - 1]) { // such as [0, 1, 2, 3(m), 4, 5(r - 1)]
                right = mid; // something smaller at left side 
            } else { // such as [2, 3, 4, 5 (m), 0, 1(r - 1)]
                left = mid + 1; // something smaller at right side since it breaks the sorted rule 
            }
        }
        return res;
    }
};
