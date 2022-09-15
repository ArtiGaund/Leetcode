class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int index=n-1;
        int left=0,right=n-1;
        while(left<=right)
        {
            int leftsq=nums[left]*nums[left];
            int rightsq=nums[right]*nums[right];
            if(leftsq>rightsq)
            {
                res[index--]=leftsq;
                left++;
            }
            else
            {
                res[index--]=rightsq;
                right--;
            }
        }
        return res;
    }
};