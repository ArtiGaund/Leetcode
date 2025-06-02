class Solution {
public:
    int count(int n)
    {
        return (n*(n+1))/2;
    }
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<=1) return n;
        int candies=0,up=0,down=0,oldslope=0;
        for(int i=1;i<n;i++)
        {
            int newslope;
            if(ratings[i]>ratings[i-1]) newslope=1;
            else if(ratings[i]<ratings[i-1]) newslope=-1;
            else newslope=0;
            if((oldslope>0 and newslope==0) or (oldslope<0 and newslope>=0))
            {
                candies+=count(up)+count(down)+max(up,down);
                up=0;
                down=0;
            }
            if(newslope>0) up++;
            else if(newslope<0) down++;
            else candies++;
            oldslope=newslope;
        }
        candies+=count(up)+count(down)+max(up,down)+1;
        return candies;
    }
};