/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //拷贝链表并插入到原结点后面
        Node*cur=head;
        while(cur)
        {
            Node* next=cur->next;
            Node* copy=(Node*)malloc(sizeof(Node));
            copy->val=cur->val;
            
            //插入
            cur->next=copy;
            copy->next=next;

            //迭代往下走
            cur=next;
        }

        cur=head;
        while(cur)
        {
            Node* copy=cur->next;
            if(cur->random!=NULL)
                copy->random=cur->random->next;
            else
                copy->random=NULL;
            cur=copy->next;
        }

        //解拷贝结点，链接拷贝结点
        Node* copyHead=NULL;
        Node* copyTail=NULL;
        cur=head;
        while(cur)
        {
            Node* copy=cur->next;
            Node* next=copy->next;

            //copy解下来尾插
            if(copyTail==NULL)
            {
                copyHead=copyTail=copy;
            }
            else
            {
                copyTail->next=copy;
                copyTail=copy;
            }

            //恢复原链表
            cur->next=next;

            //迭代往下走
            cur=next;
        }
        return copyHead;
    }
};
