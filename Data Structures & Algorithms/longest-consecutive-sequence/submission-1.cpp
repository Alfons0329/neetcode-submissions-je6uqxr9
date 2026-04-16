class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> freq(nums.begin(), nums.end());
        int maxRes = 0;

        // Instead of while(freq.size()) with curNum++, 
        // we iterate over the actual numbers we have.
        for (int num : freq) {
            // PRUNING: Only start counting if 'num' is the START of a sequence.
            // If num - 1 exists, we will handle this sequence when we hit num - 1.
            if (!freq.contains(num - 1)) {
                int curNum = num;
                int curStreak = 1;

                // Only increment when we know the next number exists
                while (freq.contains(curNum + 1)) {
                    curNum++;
                    curStreak++;
                }
                
                maxRes = max(maxRes, curStreak);
            }
        }

        return maxRes; 
    }
};