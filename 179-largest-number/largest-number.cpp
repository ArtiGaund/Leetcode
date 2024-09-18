class Solution {
public:
    vector<int> mergeSort(vector<int> &nums,int left,int right){
        if(left>=right) return {nums[left]};
        int mid=left+(right-left)/2;
        vector<int> l=mergeSort(nums,left,mid);
        vector<int> r=mergeSort(nums,mid+1,right);
        return merge(l,r);
    }
    vector<int> merge(vector<int> &left,vector<int> &right){
        vector<int> sorted;
        int leftIndex=0,rightIndex=0;
        while(leftIndex<left.size() and rightIndex<right.size()){
            if(compare(left[leftIndex],right[rightIndex])){
                sorted.push_back(left[leftIndex++]);
            }else{
                sorted.push_back(right[rightIndex++]);
            }
        }
        while(leftIndex<left.size()){
            sorted.push_back(left[leftIndex++]);
        }
        while(rightIndex<right.size()){
            sorted.push_back(right[rightIndex++]);
        }
        return sorted;
    }
    bool compare(int first,int second){
        return to_string(first)+to_string(second)>to_string(second)+to_string(first);
    }
    string largestNumber(vector<int>& nums) {
        nums=mergeSort(nums,0,nums.size()-1);
        string largestNum;
        for(int num:nums){
            largestNum+=to_string(num);
        }
        return largestNum[0]=='0'?"0":largestNum;
    }
};