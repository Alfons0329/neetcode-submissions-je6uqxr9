class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        unordered_map<int, int> pos; // map num to pos
        for(int r = 0; r < n; r ++) {
            // pos[nums[r]] = r; DO NOT CHECK HERE, since it will overwrite the old data

            // invalid window, shrink
            if (r - l > k) {
                pos.erase(nums[l]); // now duplicate allow, directly erase should be fine
                l++;
            }

            printf("l %2d \t r %2d pos[%2d] = %2d\n", l, r, nums[r], r);
            // valid window
            if (r - l <= k) {
                if (pos.count(nums[r]) && pos[nums[r]] != r) { // already exist there and index differnet and valid window
                    return true;
                }
            }
            pos[nums[r]] = r; // ONLY UPDATE Here, since we ned to check if a pos "PREVIOUSLY" exists

        }

        return false;
    }
};
