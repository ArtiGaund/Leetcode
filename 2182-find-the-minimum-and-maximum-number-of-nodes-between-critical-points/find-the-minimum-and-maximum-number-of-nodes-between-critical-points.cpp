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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2,-1);
        int minDis=INT_MAX;
        ListNode *prev=head,*cur=head->next;
        int curIndex=1,prevIndex=0,firstIndex=0;
        while(cur->next!=nullptr){
            if((cur->val<prev->val and cur->val<cur->next->val) or ( cur->val>prev->val and cur->val>cur->next->val)){
                if(prevIndex==0){
                    prevIndex=curIndex;
                    firstIndex=curIndex;
                }else{
                    minDis=min(minDis,curIndex-prevIndex);
                    prevIndex=curIndex;
                }
            }
            curIndex++;
            prev=cur;
            cur=cur->next;
        }
        if(minDis!=INT_MAX){
            int maxDis=prevIndex-firstIndex;
            res[0]=minDis;
            res[1]=maxDis;
        }
        return res;
    }
};