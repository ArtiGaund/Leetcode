class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int a=0;
        int b=products.size()-1;
        vector<vector<string>> res(searchWord.size());
        for(int i=0;i<searchWord.size() and a<=b; i++)
        {
            while(a<=b and (products[a].size()<=i or products[a][i]!=searchWord[i]))
                a++;
            while(a<=b and (products[b].size()<=i or products[b][i]!=searchWord[i]))
                b--;
            for(int k=a;k<=b and k<a+3;k++) res[i].push_back(products[k]);
        }
        return res;
    }
};