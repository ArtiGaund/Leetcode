class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
     vector<string> res;
        int i=0;
        for(int num:target){
            while(i<num-1){
                res.push_back("Push");
                res.push_back("Pop");
                i++;
            }
            res.push_back("Push");
            i++;
        }
        return res;
    }
};