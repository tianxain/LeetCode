/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    ListNode* pSlow=head;
    ListNode* pFast=head;
    while(n--)
    {
        pFast=pFast->next;
        if(pFast==NULL&&n)
        {
            return NULL;
        }
    }
    if(!pFast)
    {
        head=head->next;
        return head;
    }
    while(pFast->next)
    {
        pSlow=pSlow->next;
        pFast=pFast->next;
    }
    ListNode* del=pSlow->next;
    pSlow->next=pSlow->next->next;
    free(del);
    return head;
}
