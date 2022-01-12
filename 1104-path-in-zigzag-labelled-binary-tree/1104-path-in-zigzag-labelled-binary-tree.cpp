class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int height=log2(label);
        while(height>0)
        {
            int left=pow(2,height-1);
            int right=pow(2,height)-1;
            label=left+(right-label/2);
            res.push_back(label);
            height--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};