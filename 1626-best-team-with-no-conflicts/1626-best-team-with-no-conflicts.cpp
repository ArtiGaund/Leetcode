class Solution {
public:
    int queryBIT(vector<int> &temp,int age)
    {
        int maxScore=INT_MIN;
        for(int i=age;i>=0;i--)
            maxScore=max(maxScore,temp[i]);
        return maxScore;
    }
    void updateBIT(vector<int> &temp,int age,int cur)
    {
        for(int i=age;i<temp.size();i+=i&(-i))
            temp[i]=max(temp[i],cur);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> ageScorePair;
        for(int i=0;i<scores.size();i++)
            ageScorePair.push_back({scores[i],ages[i]});
        sort(ageScorePair.begin(),ageScorePair.end());
        int maxAge=0;
        for(int i:ages) maxAge=max(maxAge,i);
        vector<int> BIT(maxAge+1,0);
        int res=INT_MIN;
        for(auto ageScore:ageScorePair)
        {
            int cur=ageScore.first+queryBIT(BIT,ageScore.second);
            updateBIT(BIT,ageScore.second,cur);
            res=max(res,cur);
        }
        return res;
    }
};