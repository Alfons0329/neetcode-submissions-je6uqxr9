/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Intuition: intuition will be used to stack data structure to traverse from the left to right and reverse
Approach:
    1. node := left -> right, st.push(node)
    2. Use a new head dummy and then reconstructor by popping up the stack top()
    3. dummy -> stack.top() -> stack.top() until stack empty

Complexity:
    Time: O(N)
    Space: O(N) because we use an auxiliary stack to store the note going to be reversed

Dry run:
    1, 2, 3, 4, 5

Stack
bottom top
1,2,3

dummy->3->2->1->4->5
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right - left == 0 || head->next == nullptr) {
            return head; // no need to reverse
        }
        // 0, skip the non-reversed part, left prefix 
        ListNode* dummy = new ListNode(-1, head);
        ListNode* leftPrev = dummy;
        for (int i = 1; i <= left - 1; i ++) {
            leftPrev = leftPrev->next;
        }

        // 1, collecting node to the stack 
        stack<ListNode*> st;
        ListNode* cur = leftPrev->next;
        for (int i = left; i <= right; i++) {
            st.push(cur);
            cur = cur->next;
        }

        while(!st.empty()) {
            leftPrev->next = st.top();
            st.pop();
            leftPrev = leftPrev->next;
        }

        // link back
        leftPrev->next = cur;

        
        return dummy->next;
    }
};