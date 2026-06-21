/*
Intution: Search a creteria in a continuous subarray -> sliding window

Approach:
    1. Start from l (left of slinding window)
    2. Increase r (right) if abs(l - r) > k
    3. During moving the window
        add r to hashSet
        remove l from hashSet
    4. if hashSet[char] already there
        return true
    5. Otherwise return false

Dry run:
    [1, 2, 3, 1] k = 3
     l            {1}
     l  r         {1, 2}
     l     r.     {1, 2, 3}
     l        r.  {[1], 2, 3} -> true

     [2, 1, 2] k = 1
     lr          {2}
     l    r      {2, 1}
         l  r (right - left) > 1, hence increase left side
    
    Quit until r reaches end

Complexity:
    Time: O(nums.size())
    Space: O(nums.size())

*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size(), l = 0, r = 0;
        while(r < nums.size()) {
            // valid window size
            if(abs(l - r) <= k) {
                if (freq.count(nums[r])) {
                    return true; // already exist
                }
                freq[nums[r]]++;
                r++;
            } else {
            // window too big, decrase left side
                freq[nums[l]]--;
                // remove if such nums reaches zero
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
        }

        return false;
    }
};