class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        int dp=0,sum=0;
        for(int i=2;i<n;i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                dp+=1;
                sum+=dp;
            }
            else dp=0;
        }
        return sum;
    }
};