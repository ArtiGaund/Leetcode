class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> L; //store smallest N digits in the first part
        priority_queue<int,vector<int>,greater<>> R; //store greatest N digit in sec part
        long n=nums.size()/3,left=0,right=0,ans=LLONG_MAX;
        vector<long> temp(nums.size()); 
        for(int i=nums.size()-1;i>=n;i--)
        {
            R.push(nums[i]);
            right+=nums[i];
            if(R.size()>n)
            {
                right-=R.top();
                R.pop();
            }
            if(R.size()==n) temp[i]=right; //max sum
        }
        for(int i=0;i<nums.size()-n;i++)
        {
                L.push(nums[i]);
                left+=nums[i];
            if(L.size()>n)
            {
                left-=L.top();
                L.pop();
            }
            if(L.size()==n) ans=min(ans,left-temp[i+1]);
        }
        return ans;
    }
};