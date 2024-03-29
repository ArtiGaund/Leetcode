class Solution {
public:
    int findSquareSum(int num)
    {
        int sum=0,digit;
        while(num>0)
        {
            digit=num%10;
            sum+=(digit*digit);
            num/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do
        {
            slow=findSquareSum(slow);
            fast=findSquareSum(findSquareSum(fast));
        }while(slow!=fast);
        return slow==1;
    }
    
};