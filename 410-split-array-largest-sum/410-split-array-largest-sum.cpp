class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0,maxele=INT_MIN;
        for(int ele:nums)
        {
            sum+=ele;
            maxele=max(maxele,ele);
        }
        int left=maxele;
        int right=sum;
        int minsplit=0;
        while(left<=right)
        {
            int maxsumallowed=left+(right-left)/2;
            if(minSubarrayReq(nums,maxsumallowed)<=m)
            {
                right=maxsumallowed-1;
                minsplit=maxsumallowed;
            }
            else left=maxsumallowed+1;
        }
        return minsplit;
    }
    int minSubarrayReq(vector<int> &nums,int maxsumallowed)
    {
        int cursum=0,splitreq=0;
        for(int ele:nums)
        {
            if(cursum+ele<=maxsumallowed) cursum+=ele;
            else
            {
                cursum=ele;
                splitreq++;
            }
        }
        return splitreq+1;
    }
};