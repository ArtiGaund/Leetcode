class Solution {
public:
    int sumOfDivisor(vector<int> &nums,int div){
        int sum=0;
        for(int a:nums)
            sum=sum+ceil((double)a/(double)div);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(sumOfDivisor(nums,mid)<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};