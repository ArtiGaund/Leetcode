class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int size=f.size(),count=0,i=0;
        while(i<size)
        {
            if(f[i]==0 and (i==0 or f[i-1]==0) and (i==size-1 or f[i+1]==0)) 
            {
                f[i++]=1;
                count++;
            }
            if(count>=n) return true;
            i++;
        }
        return false;
    }
};