class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_w=0,sum=0;
        for(int w:weights)
        {
            max_w=max(max_w,w);
            sum+=w;
        }
        int left=max_w,right=sum;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(isfeasible(mid,weights,days))
                right=mid;
            else left=mid+1;
        }
        return left;
    }
    bool isfeasible(int cap,vector<int> &weights,int D)
    {
        int d=1,total=0;
        for(int w:weights)
        {
            total+=w;
            if(total>cap)// wait for next day
            {
                total=w;
                d++;
                if(d>D) //cannot ship in D days
                    return false;
            }
        }
        return true;
    }
};