class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cad=-1;
        int count=0;
        for(int a:nums)
        {
            if(count==0) cad=a;
            count+=(a==cad?1:-1);
        }
        return cad;
    }
};