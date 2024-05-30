class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size=arr.size();
        int count=0,prefix=0;
        unordered_map<int,int> countMap={{0,1}},totalMap;
        for(int i=0;i<size;i++){
            prefix^=arr[i];
            count+=countMap[prefix]++ *i - totalMap[prefix];
            totalMap[prefix] += i+1;
        }
        return count;
    }
};