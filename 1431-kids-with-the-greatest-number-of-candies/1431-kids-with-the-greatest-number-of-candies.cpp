class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=0;
        for(int a:candies) maxCandies=max(maxCandies,a);
        vector<bool> res;
        for(int a:candies)
            res.push_back(a+extraCandies>=maxCandies);
        return res;
    }
};