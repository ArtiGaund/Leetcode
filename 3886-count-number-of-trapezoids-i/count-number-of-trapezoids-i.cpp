class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> pointNum;
        const int mod = 1e9 + 7;
        long long res=0,sum=0;
        for(auto &point:points){
            pointNum[point[1]]++;
        }
        for(auto &[_,pNum]: pointNum){
            long long edge = (long long)pNum*(pNum-1)/2;
            res+=edge*sum;
            sum+=edge;
        }
        return res%mod;
    }
};