class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int bestSingleStart=0;
        vector<int> bestDoubleStart = {0,k};
        vector<int> bestTripleStart = { 0, k, k*2 };
        int curWindowSumSingle=0;
        for(int i=0;i<k;i++) curWindowSumSingle+=nums[i];
        int curWindowSumDouble=0;
        for(int i=k;i<k*2;i++){
            curWindowSumDouble+=nums[i];
        }
        int curWindowSumTriple=0;
        for(int i=k*2;i<k*3;i++){
            curWindowSumTriple+=nums[i];
        }
        int bestSingleSum=curWindowSumSingle;
        int bestDoubleSum=curWindowSumSingle+curWindowSumDouble;
        int bestTripleSum=curWindowSumSingle+curWindowSumDouble+curWindowSumTriple;
        int singleStartIndex=1,doubleStartIndex=k+1,tripleStartIndex=k*2+1;
        while(tripleStartIndex<=nums.size()-k){
            curWindowSumSingle=curWindowSumSingle-nums[singleStartIndex-1]+nums[singleStartIndex+k-1];
            curWindowSumDouble=curWindowSumDouble-nums[doubleStartIndex-1]+nums[doubleStartIndex+k-1];
            curWindowSumTriple=curWindowSumTriple-nums[tripleStartIndex-1]+nums[tripleStartIndex+k-1];
            if(curWindowSumSingle>bestSingleSum){
                bestSingleStart=singleStartIndex;
                bestSingleSum=curWindowSumSingle;
            }
            if(curWindowSumDouble+bestSingleSum>bestDoubleSum){
                bestDoubleStart[0]=bestSingleStart;
                bestDoubleStart[1]=doubleStartIndex;
                bestDoubleSum=curWindowSumDouble+bestSingleSum;
            }
            if(curWindowSumTriple+bestDoubleSum>bestTripleSum){
                bestTripleStart[0]=bestDoubleStart[0];
                bestTripleStart[1]=bestDoubleStart[1];
                bestTripleStart[2]=tripleStartIndex;
                bestTripleSum=curWindowSumTriple+bestDoubleSum;
            }
            singleStartIndex+=1;
            doubleStartIndex+=1;
            tripleStartIndex+=1;
        }
        return bestTripleStart;
    }
};