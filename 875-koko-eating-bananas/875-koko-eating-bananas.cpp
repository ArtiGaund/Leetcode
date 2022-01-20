class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=*max_element(piles.begin(),piles.end());
        while(left<right)
        {
            int mid=(left+right)/2;
            int hour=0;
            for(int a:piles)
                hour+=a/mid+(a%mid!=0);
            if(hour<=h) right=mid;
            else left=mid+1;
        }
        return right;
    }
};