class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(); // half open interval natively
        int m = l + (r - l) / 2; // special case for nums.sizez() == 1
        if (target == nums[m]) {
            return m;
        }

        while(l < r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) {
                return m;
            // use half-open interval [)
            } else if (target > nums[m]) { // right interval
                l = m + 1;
            } else {
                r = m;
            }   
        } 
        
        return -1;
    }
};
