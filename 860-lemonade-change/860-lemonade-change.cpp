class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5=0,n10=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5) n5++;
            else if(bills[i]==10)
            {
                if(n5) 
                {
                    n5--;
                    n10++;
                }
                else return false;
            }
            else
            {
                if(n5 and n10)
                {
                    n5--;
                    n10--;
                }
                else
                {
                    if(n5>=3) n5-=3;
                    else return false;
                }
            }
        }
        return true;
    }
};