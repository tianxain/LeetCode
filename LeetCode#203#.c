/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val){
    // //1.两个指针，在原链表上删除
    ListNode* cur=head;
    ListNode* prev=cur;
    while(cur)
    {
       if(cur->val==val)
       {
           ListNode* next=cur->next;
           if(cur==head)
           {
               head=next;
               free(cur);
               cur=next;
               prev=cur;
           }
           else
           {
                free(cur);
                cur=next;
                prev->next=cur; 
           }
       }
       else
       {
           printf("%d",__LINE__);
           prev=cur;
           cur=cur->next;
       }
    }
    printf("%d",__LINE__);
    return head;


    // //2.构造一个头节点
    // ListNode* cur=head;
    // ListNode* newHead=(ListNode*)malloc(sizeof(ListNode));
    // ListNode* newTail=newHead;
    // newHead->next=NULL;

    // while(cur)
    // {
    //     ListNode* next=cur->next;
    //     if(cur->val==val)
    //     {
    //         free(cur);
    //         cur=next;
    //     }
    //     else
    //     {
    //         newTail->next=cur;
    //         newTail=newTail->next;
    //         newTail->next=NULL;
    //         cur=next;
    //     }
    // }
    // ListNode* realHead=newHead->next;
    // free(newHead);
    // return realHead;

    ///3.尾插 
    // ListNode* newHead=NULL;
    // ListNode* newTail=NULL;
    // ListNode* cur=head;

    // while(cur!=NULL)
    // {
    //     ListNode* next=cur->next;
    //     if(cur->val==val)
    //     {
    //         free(cur);
    //         cur=next;
    //     }
    //     else
    //     {
    //         if(newTail==NULL)
    //         {
    //             newHead=newTail=cur;
    //         }
    //         else
    //         {
    //             newTail->next=cur;
    //             newTail=cur;
    //              newTail->next=NULL;
    //             cur=next;
    //         }
    //     }   
    // }
    // return newHead;
}
