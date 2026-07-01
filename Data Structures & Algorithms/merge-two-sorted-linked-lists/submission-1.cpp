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
Intuition:
    We want to merge the second list into the first one without using an obviously space to track

Approach:
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // create a dummy node to simplify 
        // the merging process
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // iterate through both linked lists
        while (head1 != nullptr && head2 != nullptr) {
        
            // add the smaller node to the merged list
            if (head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        // if any list is left, append it to
        // the merged list
        if (head1 != nullptr) {
            curr->next = head1;
        } else {
            curr->next = head2;
        }

        // return the merged list starting
        // from the next of dummy node
        return dummy->next;
    }
};
