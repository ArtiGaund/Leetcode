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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *res=nullptr,*prev=nullptr,*temp;
        int carry=0;
        while(l1 or l2)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            sum=sum%10;
            temp=new ListNode(sum);
            if(res==nullptr) res=temp;
            else prev->next=temp;
            prev=temp;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry>0) temp->next=new ListNode(carry);
        return res;
    }
};