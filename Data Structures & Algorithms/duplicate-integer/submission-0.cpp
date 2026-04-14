/*
Intution:
    For the duplicate, we can count the occurrence using hashMap

Approach:
    1. for num in nums
        if num exist in map return true
        else map[num]++

Complexity:
    Time: O(N), number len is N and each hashmap insert / look up is O(1), O(N *1) = O(N)
    Space: O(N) store as much nums as uper bound if no duplicate

*/
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> exist;

        for (int i = 0; i < nums.size(); i++) {
            if (exist.count(nums[i])) {
                return true;
            }
            exist[nums[i]] = true;
        }

        return false;
    }
};

/* Dry run

[1, 2, 3, 4]
    i = 0, [<1, true>]
    i = 1, [<1, true>, <2, true>]
    i = 2, [<1, true>, <2, true>, <3, true>]
    i = 3, [<1, true>, <2, true>, <3, true>, <4, true>]

    return false

[1, 2, 3, 3] -
    i = 0, [<1, true>]
    i = 1, [<1, true>, <2, true>]
    i = 2, [<1, true>, <2, true>, <3, true>]
    i = 3, found <3, true> -> return true 
*/