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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode *first=head,*sec=head;
        for(int i=0;i<k;i++) sec=sec->next;
        while(sec!=nullptr)
        {
            first=first->next;
            sec=sec->next;
        }
        int right=first->val;
        ListNode *node=head;
        for(int i=0;i<k-1;i++)
            node=node->next;
        int left=node->val;
        node->val=right;
        first->val=left;
        return head;
    }
};