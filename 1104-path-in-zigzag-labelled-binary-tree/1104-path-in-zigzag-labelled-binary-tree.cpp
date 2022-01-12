class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label); //take bottom up approach so the label itself is included
        int height=log2(label); //height of label from root
        while(height!=0)
        {
            int left=pow(2,height-1); //rank of left limit of prev level
            int right=pow(2,height)-1; //rank of right limit of prev level
            label=left+(right-label/2); //prev level is sorted in diff order than cur level so new 
                                        // level is adjusted 
            res.push_back(label);
            height--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};