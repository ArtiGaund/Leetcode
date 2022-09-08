class Solution {
public:
    vector<int> temp,temp2;
    Solution(vector<int>& nums) {
        temp=nums;
        temp2=nums;
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        int random=rand()%temp.size();
        swap(temp2[random],temp2[0]);
        return temp2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */