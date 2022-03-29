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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        return solve(head);
    }
    ListNode *solve(ListNode* cur,ListNode *prev=nullptr)
    {
        if(cur->next==nullptr)
        {
            cur->next=prev;
            return cur;
        }
        ListNode *temp=cur->next;
        cur->next=prev;
        return solve(temp,cur);
    }
};