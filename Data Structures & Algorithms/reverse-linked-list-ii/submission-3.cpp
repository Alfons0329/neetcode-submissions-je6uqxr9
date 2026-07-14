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
        /* 0, 
            skip the non-reversed part, left prefix. e.g. for 1, 2, [3, 4, 5], 6, leftPrev should stopped at 2 
                                                                     L = 3 R = 5

            detail
            i = 1, leftPrev = dummy->1, i++ to 2
            i = 2, leftPrev = 1->2. i++ to 3, LOOP TERMINATED
            (NOT 1, because loop i is POST INCREMENT)
        */

        ListNode* dummy = new ListNode(-1, head);
        ListNode* leftPrev = dummy;
        for (int i = 1; i <= left - 1; i++) {
            leftPrev = leftPrev->next;
        }

        /* 1, 
            collecting node to the stack e.g. for 1, 2, [3, 4, 5], 6
                                                        L = 3 R = 5
            
            detail
            i = 3, cur = 3->4, i++ to 4, st = [3]
            i = 4, cur = 4->5, i++ to 5, st = [3, 4] (top at right)
            i = 5, cur = 5->6, i++ to 6, st = [3, 4, 5] (top at right)
            (cur NOT 5, because loop i is POST INCREMENT, so it moves 3 steps ahead from node = 3, which cur = 6 now)
            (also stack is not [4, 5, 6] because we push cur BEFORE move to next)
        */
        stack<ListNode*> st;
        ListNode* cur = leftPrev->next;
        for (int i = left; i <= right; i++) {
            st.push(cur);
            cur = cur->next;
        }

        /*2,
            connect the leftPrev to the reversed part for 1, 2, [3, 4, 5], 6, 
            leftPrev should stopped at 2, and cur is now 6 (NOT 5, because cur is POST INCREMENT)

            leftPrev->next = 5, stack [5, 4, 3]
            leftPrev = leftPrev->next = 5, stack [4, 3]

            leftPrev->next = 4, stack [4, 3]
            leftPrev = leftPrev->next = 4, stack [3]

            leftPrev->next = 3, stack [4, 3] 
            leftPrev = leftPrev->next = 3, stack []

        */
        while(!st.empty()) {
            leftPrev->next = st.top();
            st.pop();
            leftPrev = leftPrev->next;
        }

        /*
            cur at 6
            leftPrev 3 (original 5th node, but value after reversed is 3 now)

            finally connect leftPrev->cur makes 3->6
        */
        leftPrev->next = cur;

        
        return dummy->next;
    }
};