//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string begin, string end, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({begin});
        if(st.find(end)==st.end()) return {}; //end word is not in list
        vector<string> usedOnLevel;
        usedOnLevel.push_back(begin);
        int level=0;
        vector<vector<string>> res;
        while(!q.empty())
        {
            vector<string> temp=q.front();
            q.pop();
            //erase all words that has been in the previous levels to tranform
            if(temp.size()>level)
            {
                level++;
                for(auto it:usedOnLevel)
                    st.erase(it);
            }
            string word=temp.back();
            if(word==end)
            {
                //first sequence where we reached end
                if(res.size()==0) res.push_back(temp);
                else if(res[0].size()==temp.size()) res.push_back(temp); 
                    
            }
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        temp.push_back(word);
                        q.push(temp);
                        // mark visited on the level
                        usedOnLevel.push_back(word);
                        temp.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends