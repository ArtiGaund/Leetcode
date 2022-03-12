/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
           return head;
        Node* cur=head,*temp;
        while(cur)
        {
            temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }
        cur=head;
        while(cur)
        {
            if(cur->next)
                cur->next->random=cur->random?cur->random->next:cur->random;
            cur=cur->next?cur->next->next:cur->next;
        }
        Node* original=head,*copy=head->next;
        temp=copy;
        while(original&&copy)
        {
            original->next=original->next?original->next->next:original->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }
};