class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        priority_queue<int> maxH;
        priority_queue<int,vector<int>,greater<int>> minH;
        unordered_map<int,int> mp;
        int i=0;
        while(i<k) //adding in maxH
            maxH.push(nums[i++]);
        for(int j=0;j<k/2;j++) //putting half element from maxh to minh to balance both 
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        int balance=0;
        while(true) //for remaining elements
        {
            if(k&1) //k is odd
                medians.push_back(maxH.top());
            else
                medians.push_back(((double)maxH.top()+(double)minH.top())*0.5);
            if(i>=nums.size()) break; //processed all elements;
            int out_num=nums[i-k]; //outgoing number
            int in_num=nums[i++]; //incoming number
            mp[out_num]++;
            balance=0;
            balance+=(out_num<=maxH.top()?-1:1); //outgoing number exit
            if(!maxH.empty() and in_num<=maxH.top())
            {
                balance++;
                maxH.push(in_num);
            }
            else
            {
                balance--;
                minH.push(in_num);
            }
            if(balance<0) //maxh need more valid no
            {
                maxH.push(minH.top());
                minH.pop();
                balance++;
            }
            if(balance>0) //minh need more valid no
            {
                minH.push(maxH.top());
                maxH.pop();
                balance--;
            }
            while(mp[maxH.top()]) //invalid number in maxh, outgoing no reach top of maxh
            {
                mp[maxH.top()]--;
                maxH.pop();
            }
            while(!minH.empty() and mp[minH.top()])
            {
                mp[minH.top()]--;
                minH.pop();
            }
        }
        return medians;
    }
};