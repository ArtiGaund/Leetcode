class Solution {
public:
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> sortedPeople(people.begin(),people.end());
        sort(sortedPeople.begin(),sortedPeople.end());
        sort(flowers.begin(),flowers.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        unordered_map<int,int> dict;
        for(int p:sortedPeople)
        {
            while(i<flowers.size() and flowers[i][0]<=p)
            {
                pq.push(flowers[i][1]);
                i++;
            }
            while(!pq.empty() and pq.top()<p)
                pq.pop();
            dict[p]=pq.size();
        }
        vector<int> res;
        for(int p:people)
            res.push_back(dict[p]);
        return res;
    }
};