class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use hash set to track occurrentce
        unordered_map<int, int> exiPos; // exist at which positoin ?
        int n = nums.size();
        for (int i = 0 ; i < n; i ++) {
            // complement alreay exists
            int delta = target - nums[i];
            if (exiPos.count(delta)) {
                return {min(exiPos[delta], i), max(exiPos[delta], i)};
            }
            exiPos[nums[i]] = i;
        }

        return {};
    }
};
