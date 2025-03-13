class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),sum=0,k=0;
        vector<int> temp(n+1);
        for(int index=0;index<n;index++){
            while(sum+temp[index]<nums[index]){
                k++;
                if(k>queries.size()) return -1;
                int left=queries[k-1][0],right=queries[k-1][1],val=queries[k-1][2];
                if(right>=index){
                    temp[max(left,index)]+=val;
                    temp[right+1]-=val;
                }
            }
            sum+=temp[index];
        }
        return k;
    }
};