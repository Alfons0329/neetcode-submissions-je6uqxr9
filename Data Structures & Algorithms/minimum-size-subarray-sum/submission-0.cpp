class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, total = 0;
        int res = INT_MAX;

        for (int R = 0; R < nums.size(); R++) {
            total += nums[R];

            // enough amount, shrink the subarray as 
            // shorter as possible until no longer match >= target criteria
            while (total >= target) {
                res = min(R - L + 1, res);
                total -= nums[L];
                L++;
            }
        }

        // no result to find
        if (res == INT_MAX) {
            return 0;
        } 
        return res;
    }
};