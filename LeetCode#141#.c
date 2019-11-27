/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode  ListNode;
bool hasCycle(struct ListNode *head) {
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
