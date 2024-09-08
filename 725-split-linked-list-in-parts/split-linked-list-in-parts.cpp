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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *cur=head;
        int n=0;
        while(cur){
            cur=cur->next;
            n++;
        }
        int width=n/k,rem=n%k;
        vector<ListNode*> res(k);
        cur=head;
        for(int i=0;i<k;i++){
            ListNode *root=cur;
            for(int j=0;j<width+(i<rem?1:0)-1;j++)
                if(cur) cur=cur->next;
            if(cur){
                ListNode *prev=cur;
                cur=cur->next;
                prev->next=nullptr;
            }
            res[i]=root;
        }
        return res;
    }
};