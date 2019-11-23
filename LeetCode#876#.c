/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode  ListNode;
struct ListNode* middleNode(struct ListNode* head){
    //1.快慢指针（一次遍历）
    ListNode* pSlow=head;
    ListNode* pFast=head;

    while(pFast!=NULL && pFast->next !=NULL)
    {
        pSlow=pSlow->next;
        pFast=pFast->next->next;
    }
    return pSlow;

    // //2.两次遍历
    // ListNode* cur=head;
    // int count=0;
    // while(cur)
    // {
    //     count++;
    //     cur=cur->next;
    // }
    // for(int i=0;i<count/2;i++)
    // {
    //     head=head->next;
    // }
    // return head;
}
