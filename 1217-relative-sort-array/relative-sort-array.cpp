class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max_ele = *max_element(arr1.begin(),arr1.end());
        vector<int> count(max_ele+1);
        for(int ele:arr1) count[ele]++;
        vector<int> res;
        for(int ele:arr2){
            while(count[ele]>0){
                res.push_back(ele);
                count[ele]--;
            }
        }
        for(int num=0;num<=max_ele;num++){
            while(count[num]>0){
                res.push_back(num);
                count[num]--;
            }
        }
        return res;
    }
};