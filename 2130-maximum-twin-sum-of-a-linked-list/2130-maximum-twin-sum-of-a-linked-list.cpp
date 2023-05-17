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
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *nextNode,*prev=nullptr;
        while(slow)
        {
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        int maxSum=0;
        ListNode *start=head;
        while(prev)
        {
            maxSum=max(maxSum,start->val+prev->val);
            prev=prev->next;
            start=start->next;
        }
        return maxSum;
    }
};