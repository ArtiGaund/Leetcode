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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode *slow=head,*fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
};