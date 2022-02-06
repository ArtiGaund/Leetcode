class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        vector<int> temp;
        if(num<0)
        {
            num=num*-1;
            while(num>0)
            {
                temp.push_back(num%10);
                num=num/10;
            }
            sort(temp.begin(),temp.end(),greater<>());
            num=0;
            for(int a:temp)
            {
                num=num*10+a;
            }
            return -1*num;
        }
        else
        {
            while(num>0)
            {
                temp.push_back(num%10);
                num=num/10;
            }
            sort(temp.begin(),temp.end());
            int i=0;
            int zero=0;
            while(temp[i]==0)
            {
                zero++;
                i++;
            }
            num=temp[i];
            while(zero--)
            {
                num=num*10+0;
            }
            for(int j=i+1;j<temp.size();j++)
                num=num*10+temp[j];
            
            return num;
        }
    }
};