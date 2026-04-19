/*
Intution: Construct the prefix and suffix product

Approoach:
    1. prefix product
    2. postfix product
    3. res[i]  
        edge case: if i == nums.size() - 1 then prefix[i-1]
        edge case: if i == 0, then postfix[i+1]
        normally: postfix[i+1] * prefix[i-1]

Complexity:
    Time: O(nums.size()) since we construct prefix and postfix, and then iteratr the result again
    Space: O(nums.zie()) to consturct the tracking array
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);

        // init
        prefix[0] = nums[0];
        postfix[n - 1] = nums[n - 1];

        // construct prefix
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        // cosntruct postfix
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i];
        }

        // get result
        vector<int> res(n);
        for (int i = 0; i < n; i ++) {
            if (i + 1 == n) {
                res[i] = prefix[i - 1];
            } else if (i == 0) {
                res[i] = postfix[i + 1];
            } else {
                res[i] = prefix[i - 1] * postfix[i + 1];
            }
            
        }

        return res;
    }
};
