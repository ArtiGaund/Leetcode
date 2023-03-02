class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,index=0;
        while(i<chars.size())
        {
            int j=i;
            while(j<chars.size() and chars[i]==chars[j]) j++;
            chars[index++]=chars[i];
            if(j-i>1)
            {
                for(char ch:to_string(j-i)) chars[index++]=ch;
            }
            i=j;
        }
        return index;
    }
};