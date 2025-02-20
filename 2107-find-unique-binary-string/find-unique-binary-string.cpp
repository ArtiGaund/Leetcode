class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res="";
        for(int i=0;i<nums.size();i++){
            char temp=nums[i][i];
            res+=temp=='0'?'1':'0';
        }
        return res;
    }
};