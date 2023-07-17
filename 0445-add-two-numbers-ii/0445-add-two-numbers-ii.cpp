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
    ListNode *addAtHead(ListNode *head,ListNode *n)
    {
        if(head==nullptr) return n;
        n->next=head;
        head=n;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode *head=nullptr;
        int sum,c=0;
        while(!s1.empty() and !s2.empty())
        {
            sum=c+s1.top()+s2.top();
            s1.pop();
            s2.pop();
            c=sum/10;
            sum=sum%10;
            ListNode *newNode=new ListNode(sum);
            head=addAtHead(head,newNode);
        }
        while(!s1.empty())
        {
            sum=c+s1.top();
            s1.pop();
            c=sum/10;
            sum=sum%10;
            ListNode *newNode=new ListNode(sum);
            head=addAtHead(head,newNode);
        }
        while(!s2.empty())
        {
            sum=c+s2.top();
            s2.pop();
            c=sum/10;
            sum=sum%10;
            ListNode *newNode=new ListNode(sum);
            head=addAtHead(head,newNode);
        }
        if(c>0)
        {
            ListNode *newNode=new ListNode(c);
            head=addAtHead(head,newNode);
        }
        return head;
    }
};