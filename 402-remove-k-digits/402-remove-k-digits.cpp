class Solution {
public:
    string removeKdigits(string nums, int k) {
        string res;
        int keep=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            while(res.size()>0 and res.back()>nums[i] and k>0)
            {
                res.pop_back();
                k--;
            }
            res.push_back(nums[i]);
        }
        res.erase(keep,string::npos);
        //trim leading zero
        int s=0;
        while(s<(int)res.size()-1 and res[s]=='0') s++;
        res.erase(0,s);
        return res==""?"0":res;
    }
};