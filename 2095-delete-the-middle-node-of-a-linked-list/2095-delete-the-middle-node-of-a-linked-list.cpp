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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int mid=len/2;
        // if(len%2==1)
        // {
            temp=head;
            while(mid>1)
            {
                mid--;
                temp=temp->next;
            }
                
            temp->next=temp->next->next;
        // }
        // else
        // {
        //     ListNode *temp=head;
        //     while(mid--)
        //         temp=temp->next;
        //     temp->next=temp->next->next;
        // }
        return head;
    }
};