class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int,int> mp; //keep track of invalid no. It holds the count of occurrence of all such no that have been invalidated and yet remain in heaps
        priority_queue<int> low; //max heap
        priority_queue<int,vector<int>,greater<int>> high; //min heap
        int i=0;
        while(i<k) //initialize the heap
            low.push(nums[i++]);
        for(int j=0;j<k/2;j++)
        {
            high.push(low.top());
            low.pop();
        }
        int balance=0;
        while(true)
        {
            medians.push_back(k&1?low.top():((double)low.top()+(double)high.top())*0.5); //get median
            if(i>=nums.size()) break; //if all elements are processed
            int out_num=nums[i-k]; //outgoing element
            int in_num=nums[i++]; //incoming element
            balance=0; //balance factor
            balance+=(out_num<=low.top()?-1:1); //out_num exits window
            mp[out_num]++;
            if(!low.empty() and in_num<=low.top()) //in_num enters window
            {
                balance++;
                low.push(in_num);
            }
            else
            {
                balance--;
                high.push(in_num);
            }
            if(balance<0) //rebalance heaps low needs more valid elements
            {
                low.push(high.top());
                high.pop();
                balance++;
            }
            if(balance>0) //high needs more valid elements
            {
                high.push(low.top());
                low.pop();
                balance--;
            }
            while(mp[low.top()]) //remove invalid no that should be discarded from heap tops
            {
                mp[low.top()]--;
                low.pop();
            }
            while(!high.empty() and mp[high.top()])
            {
                mp[high.top()]--;
                high.pop();
            }
        }
        return medians;
    }
};