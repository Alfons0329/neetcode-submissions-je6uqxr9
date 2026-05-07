
/*
Intuition: Since to track the happened before now (backtrack, revisit) we cna use stack

Approach:
    1. init res with 0
    2. st trace <temp, pos>
    3. for temp[idx] temps
        while stack non empty, and temp > st.top()
            res[st.top().pos] = idx - st.top().pos
        
        st.push(<temp[idx], idx>)

Complexity:
    Time: O(temps.size()) at most [n, n-1, n-2.....0] we push all the temps to stack, O(1) for push every elemtn, total O(temps.sizze())
    Space: O(temps.size()) same as above

*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int cur = temps[i];

            while (!st.empty() && st.top().first < cur) {
                // count days duration delta, how many days after can reach higher
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({cur, i});
        }

        return res;
    }
};
