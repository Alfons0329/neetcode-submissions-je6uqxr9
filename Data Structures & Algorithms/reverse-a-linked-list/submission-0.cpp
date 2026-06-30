/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

To reverse a link list is quite straightforward 
Here is an example
    n1 -> n2 -> null
    Will become
    n2 -> n1 -> null

    The idea is to reverse the list and have two pointers the previous and the current
    1. Save the next pointer of the current. (nextSave = cur -> next), 
    The first step is very essential because we ensure after 
    reverse we still keep track of the original next node so this has to be done in the first 
    and cannot be done after the second step otherwise we will loop to ourself back

    2. Then then move the current next to the previous (cur -> next = prev)


    3. Find the above step two and three ensure the pointer is reversed.

    4. Then we move our group completely forward by the following
        5-1: prev = cur
        5-2: cur = nextSave

For complexity analysis
    The time complexity will be linear because we illiterate the LL at once
    Space complexity will be constant because there is no extra linear space to store the data

 */


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* savedNext = nullptr;

        while(cur) {
            // saved next
            savedNext = cur->next;
            // reverse
            cur->next = prev;

            // move group forward
            prev = cur;
            cur = savedNext;
        }

        return prev;
    }
};
