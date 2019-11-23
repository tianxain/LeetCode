/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
    //头插（无头）
    if(head==NULL||head->next==NULL)//空表或只有一个节点
    {
        return head;
    }

    
    ListNode* newHead=head;//将第一个结点作为最后一个结点
    ListNode* cur=head->next;//当前节点指向第二个
    newHead->next=NULL;//最后一个结点指向空

    while(cur)//遍历n-1次
    {
        ListNode* next=cur->next;//保存当前结点的下一个结点
        cur->next=newHead;//插入
        newHead=cur;
         cur=next;
    }
    
    return newHead;
}
