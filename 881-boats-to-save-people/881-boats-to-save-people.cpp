class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int totalBoats=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            totalBoats++;
            if(people[i]+people[j]<=limit)
                i++;
            j--;
        }
        return totalBoats;
    }
};