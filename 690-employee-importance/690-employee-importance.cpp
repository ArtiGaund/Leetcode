/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> mp;
        for(Employee* e:employees) mp[e->id]=e;
        return dfs(id,mp);
    }
    int dfs(int id,unordered_map<int,Employee*> &mp)
    {
        Employee *e=mp[id];
        int ans=e->importance;
        for(int subid:e->subordinates) ans+=dfs(subid,mp);
        return ans;
    }
};