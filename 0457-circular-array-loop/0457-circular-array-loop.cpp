class Solution {
public:
    int findNextIndex(vector<int> &nums,bool isForward,int index)
    {
        bool direction=(nums[index]>=0);
        if(isForward!=direction) return -1;
        int nextIndex=(index+nums[index]+nums.size())%nums.size();
        if(index==nextIndex) nextIndex=-1;
        return nextIndex;
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            bool isForward=(nums[i]>=0);
            int slow=i,fast=i;
            do
            {
                slow=findNextIndex(nums,isForward,slow);
                fast=findNextIndex(nums,isForward,fast);
                if(fast!=-1)
                    fast=findNextIndex(nums,isForward,fast);
            }while(slow!=-1 and fast!=-1 and slow!=fast);
            if(slow!=-1 and slow==fast) return true;
        }
        return false;
    }
};