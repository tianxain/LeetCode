/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode  ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    //第一种
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            //求环的入口
            ListNode* meet=slow;
            ListNode* start=head;
            while(meet!=start)
            {
                meet=meet->next;
                start=start->next;
            }
            return meet;
        }
    }
    return NULL;   

    //第二种：转换成链表相交问题
}
