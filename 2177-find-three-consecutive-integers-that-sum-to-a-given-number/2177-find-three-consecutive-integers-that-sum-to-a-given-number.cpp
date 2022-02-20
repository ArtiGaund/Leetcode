class Solution {
public:
    // 1) if num is divisible by 3 then only ans exist
    // 2) ans will be mid-1,mid,mid+1
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};
        long long mid=num/3;
        return {mid-1,mid,mid+1};
    }
};