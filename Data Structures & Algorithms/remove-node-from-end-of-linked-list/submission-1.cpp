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
Intuition: we can use a two pointer-like approach

Approach:
    Define the first pointer as current 
    Define the second pointer as previous

    prev -> cur it should follow that previous is the n+1th pointer before the current

    This example 1. 2. 3.  4
                 p.    c (diff = 2)
    
    Let the previous pointer stays at the ground and that the current traverse is the first

    Then we move both pointer simultaneously
    1.  2.  3.  4
    p.      c
        p.      c
    
    Once the next pointer of the current pointer is the new, 
    which means we have reached our destination to remove because 
    the previous pointers next is just the node we want to remove

    To remove the pointer
    Simply get the prev and its next

    prevNext = prev->next //store the next of next
    prev->next = prevNext->next // they skipped the next point of marking as deleted

    Let's also walk through some edge cases

    head = 5, n = 1
           pc
           at here, the next point of the current point is already null, 
           so we already know that this is a single-node link list we can directly remove this one
           Directly return the null pointer


    head = 1    2, n = 2
           pc
           p.   c
           p    c
    
    head node is subject to change so we can also use a dummy node to point to head for Easy management
    The dummy asked as a "prenode" to the following LL
    dummy -> 1 -> 2 -> null
    fast
    slow

    This will solve the case [1, 2] and 2

    dummy -> 1 -> 2 -> null
    fast.         slow
    fast -> next = fast -> next -> next , skip 1 --> this makes the head 1 skipped
    resturn dummy -> next still guarantees the correct answer 
    because the dummy next originally was 1 and is skipped by the fast pointer 
    so we directly returned the dummy next rather than head pointer
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast;
        ListNode* slow;
        ListNode* dummy = new ListNode(0); // real pointer, need initialize, only need to new dummy since 
        // other two ptr sare used to track the position
        dummy->next = head; // only need to new dummy 
        fast = dummy;
        slow = dummy;


        // fast pointer, move n steps forward
        while (n && fast->next) {
            fast = fast->next;
            n--;
        }

        // move fast and slow pointer at the same time
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // remove
        slow->next = slow->next->next;

        return dummy->next;
    }
};
