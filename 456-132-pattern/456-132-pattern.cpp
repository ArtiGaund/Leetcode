class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> min_v(n);
        min_v[0]=nums[0];
        for(int i=1;i<n;i++)
            min_v[i]=min(nums[i],min_v[i-1]);
        stack<int> s;
        for(int j=n-1;j>=0;j--)
        {
            while(!s.empty() and s.top()<nums[j])
            {
                if(s.top()>min_v[j]) return true;
                s.pop();
            }
            s.push(nums[j]);
        }
        return false;
    }
};