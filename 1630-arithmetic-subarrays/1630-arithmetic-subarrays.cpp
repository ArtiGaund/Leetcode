class Solution {
public:
    bool check(vector<int> &temp){
       int minE=INT_MAX;
        int maxE=INT_MIN;
        unordered_set<int> st;
        for(int num:temp){
            minE=min(minE,num);
            maxE=max(maxE,num);
            st.insert(num);
        }
        if((maxE-minE)%(temp.size()-1)!=0) return false;
        int diff=(maxE-minE)/(temp.size()-1);
        int cur=minE+diff;
        while(cur<maxE){
            if(st.find(cur)==st.end()) return false;
            cur+=diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            vector<int> temp(begin(nums)+l[i],begin(nums)+r[i]+1);
            res.push_back(check(temp));
        }
        return res;
    }
};