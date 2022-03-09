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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
         ListNode* dummy=new ListNode;
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            while(cur->next!=NULL&&cur->next->val==prev->next->val)
                cur=cur->next;
            if(prev->next==cur)
                prev=prev->next;
            else
                prev->next=cur->next;
            cur=cur->next;
        }
        head=dummy->next;
        return head;
    }
};