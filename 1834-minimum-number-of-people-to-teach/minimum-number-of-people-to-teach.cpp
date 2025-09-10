class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> st;
        for(auto frndshp:friendships){
            unordered_map<int,int> mp;
            bool common=false;
            for(int lan:languages[frndshp[0]-1]){
                mp[lan]=1;
            }
            for(int lan:languages[frndshp[1]-1]){
                if(mp[lan]){
                    common=true;
                    break;
                }
            }
            if(!common){
                st.insert(frndshp[0]-1);
                st.insert(frndshp[1]-1);
            }
        }
        int max_cnt=0;
        vector<int> cnt(n+1,0);
        for(auto frndshp:st){
            for(int lan:languages[frndshp]){
                cnt[lan]++;
                max_cnt=max(max_cnt,cnt[lan]);
            }
        }
        return st.size()-max_cnt;
    }
};