class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> pairProductsFreq;
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pairProductsFreq[nums[i]*nums[j]]++;
            }
        }
        for(auto [val,freq]:pairProductsFreq){
            int equalProduct=(freq-1)*freq/2;
            total+=8*equalProduct;
        }
        return total;
    }
};