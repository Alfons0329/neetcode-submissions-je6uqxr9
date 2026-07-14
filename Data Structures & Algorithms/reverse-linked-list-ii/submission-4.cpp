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
// Stitching a sublist using stack-based reversal
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode* leftPrev = dummy;
    
    // 1. Locate Prefix Boundary
    for (int i = 1; i < left; i++) {
        leftPrev = leftPrev->next;
    }
    
    // 2. Collect Subsegment & naturally locate Suffix Boundary
    stack<ListNode*> st;
    ListNode* cur = leftPrev->next;
    for (int i = left; i <= right; i++) {
        st.push(cur);
        cur = cur->next; // After loop, cur points to Suffix Head!
    }
    
    // 3. Reweave reversed subsegment
    ListNode* prev = leftPrev;
    while (!st.empty()) {
        prev->next = st.top();
        st.pop();
        prev = prev->next;
    }
    
    // 4. Attach Suffix Boundary
    prev->next = cur;
    
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}
};