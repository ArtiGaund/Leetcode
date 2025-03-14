class Solution {
public:
bool canAllocateCandies(vector<int> &candies,long long k,int noOfCandies){
    long long int maxNoOfChildren=0;
    for(int i=0;i<candies.size();i++){
        maxNoOfChildren+=candies[i]/noOfCandies;
    }
    return maxNoOfChildren>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandiesInPile=0;
        for(int candy:candies){
            maxCandiesInPile=max(maxCandiesInPile,candy);
        }
        int left=0,right=maxCandiesInPile;
        while(left<right){
            int mid=(left+right+1)/2;
            if(canAllocateCandies(candies,k,mid)) left=mid;
            else right=mid-1;
        }
        return left;
    }
};